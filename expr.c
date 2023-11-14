#include "expr.h"
#include "scope.h"
#include <string.h>
#include <stdlib.h>


struct expr *expr_create(expr_t kind, struct expr *left, struct expr *right)
{
    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}

struct type *expr_typecheck(struct expr *e){
    if(!e) return 0;

    struct type *lt = expr_typecheck(e->left);
    struct type *rt = expr_typecheck(e->right);
    struct type *result;

    switch (e->kind)
    {
    case EXPR_INTEGER_LITERAL:
        result = type_create(TYPE_INTEGER, 0, 0);
        break;
    case EXPR_BOOLEAN_LITERAL:
        result = type_create(TYPE_BOOLEAN, 0, 0);
        break;
    case EXPR_CHARACTER_LITERAL:
        result = type_create(TYPE_CHARACTER, 0, 0);
        break;
    case EXPR_STRING_LITERAL:
        result = type_create(TYPE_STRING, 0, 0);
        break;
    case EXPR_FLOAT_LITERAL:
        result = type_create(TYPE_FLOAT, 0, 0);
        break;
    case EXPR_ARRAY_LITERAL: // array initializer {1,2,3,4,5}, each element match array subtype and length
        if(!e->left){
            // printf("type error: array initializer must have type\n");
            // type_error = 1;
            result = type_create(TYPE_ARRAY, 0, 0);
        }else{
            struct expr *inner = e->left; // first element
            struct type *element_type = expr_typecheck(inner);
            while (inner)
            {
                if(!type_equals(element_type, expr_typecheck(inner))){
                    printf("type error: array element mixed\n");
                    type_error = 1;
                }
                inner = inner->next;
            }
            result = type_create(TYPE_ARRAY, element_type, 0);
        }
        break;
    case EXPR_IDENTIFIER:
        result = type_copy(e->symbol->type);
        break;
    case EXPR_ADD:
    case EXPR_SUB:
    case EXPR_MUL:
    case EXPR_DIV:
    case EXPR_MOD:
    case EXPR_EXP:
        if(!type_equals(lt, rt)){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        if((lt->kind!=TYPE_INTEGER && lt->kind!=TYPE_FLOAT) || (rt->kind!=TYPE_INTEGER && rt->kind!=TYPE_FLOAT)){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        result = type_create(TYPE_INTEGER, 0, 0);
        break;
    
    case EXPR_EQUAL:
    case EXPR_NEQUAL:
        if(!type_equals(lt, rt)){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        if(lt->kind == TYPE_VOID || lt->kind == TYPE_ARRAY || lt->kind==TYPE_FUNCTION){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        result = type_create(TYPE_BOOLEAN, 0, 0);
        break;
    case EXPR_LESS:
    case EXPR_LE:
    case EXPR_GREATER:
    case EXPR_GE:
        if(!type_equals(lt, rt)){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        if(lt->kind != TYPE_INTEGER && lt->kind != TYPE_FLOAT){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        result = type_create(TYPE_BOOLEAN, 0, 0);
        break;
    case EXPR_AND:
    case EXPR_OR:
        if(lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        result = type_create(TYPE_BOOLEAN, 0, 0);
        break;
    case EXPR_NOT:
        if(rt->kind != TYPE_BOOLEAN){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        result = type_create(TYPE_BOOLEAN, 0, 0);
        break;
    case EXPR_NEG:
        if(rt->kind != TYPE_INTEGER && rt->kind != TYPE_FLOAT){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        result = type_create(TYPE_INTEGER, 0, 0);
        break;
    case EXPR_POSTDEC:
    case EXPR_POSTINC:
        if(lt->kind != TYPE_INTEGER && lt->kind != TYPE_FLOAT){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        result = type_create(TYPE_INTEGER, 0, 0);
        break;
    case EXPR_ARRAY_SUB: //a[i]
        if(lt->kind == TYPE_ARRAY){
            if(rt->kind != TYPE_INTEGER){
                printf("type error: array index must be integer\n");
                type_error = 1;
            }
            result = type_copy(lt->subtype);
        }else{//not array
            printf("type error: (%s) is not an array\n", e->left->name);
            type_error = 1;
            result = type_copy(lt);
        }
        break;
    case EXPR_ASSIGN:
        if(!type_equals(lt, rt)){
            expr_print_type_error(e->kind, e, lt, rt);
            type_error = 1;
        }
        if(e->left->kind == EXPR_INTEGER_LITERAL || e->left->kind == EXPR_BOOLEAN_LITERAL || e->left->kind == EXPR_CHARACTER_LITERAL || e->left->kind == EXPR_STRING_LITERAL || e->left->kind == EXPR_FLOAT_LITERAL){
            printf("type error: cannot assign to non-lvalue\n");
            type_error = 1;
        }
        result = type_copy(rt); // return right type, left type could be not value
        break;

    case EXPR_FUNC: // function call
        if(lt->kind != TYPE_FUNCTION){
            printf("type error: (%s) is not a function\n", e->left->name);
            type_error = 1;
            result = type_copy(lt);
        }else{
            
            struct param_list *p = e->left->symbol->type->params;
            struct expr *arg = e->right;
            if(p && !arg || !p && arg){
                printf("type error: function (%s) argument number mismatch\n", e->left->name);
                type_error = 1;
            }
            while (p && arg)
            {
                struct type *arg_type = expr_typecheck(arg);
                if(arg_type->kind==TYPE_VOID){
                    printf("type error: function (%s) argument cannot be void\n", e->left->name);
                    type_error = 1;
                }
                if(arg_type->kind == TYPE_FUNCTION){
                    printf("type error: function (%s) argument cannot be function\n", e->left->name);
                    type_error = 1;
                }
                if(arg_type->kind == TYPE_ARRAY){
                    printf("type error: function (%s) argument cannot be array\n", e->left->name);
                    type_error = 1;
                }
                if(!type_equals(p->type, arg_type)){
                    printf("type error: function (%s) argument type mismatch\n", e->left->name);
                    type_error = 1;
                }
                p = p->next;
                arg = arg->next;
                if(p && !arg || !p && arg){
                    printf("type error: function (%s) argument number mismatch\n", e->left->name);
                    type_error = 1;
                }
            }
            result = type_copy(lt->subtype);
        }
        break;
    
    default:
        printf("type error: invalid expression kind\n");
        exit(1);
        break;
    }

    type_delete(lt);
    type_delete(rt);

    return result;
}

void expr_print_type_error(expr_t e_type, struct expr *e, struct type *lt, struct type *rt)
{
    printf("type error: cannot do operation ");
    printf("%s ", expr_type_to_str(e_type));
    type_print(lt);
    printf(" (");
    expr_print(e->left);
    printf(") to a ");
    type_print(rt);
    printf(" (");
    expr_print(e->right);
    printf(")\n");
}

const char *expr_type_to_str(expr_t type){
    switch (type)
    {
    case EXPR_ADD:
        return "add";
    case EXPR_SUB:
        return "sub";
    case EXPR_MUL:
        return "mul";
    case EXPR_DIV:  
        return "div";
    case EXPR_MOD:
        return "mod";
    case EXPR_EXP:
        return "exp";
    case EXPR_NOT:
        return "not";
    case EXPR_NEG:
        return "neg";
    case EXPR_LESS:
        return "less";
    case EXPR_LE:
        return "le";
    case EXPR_GREATER:
        return "greater";
    case EXPR_GE:
        return "ge";
    case EXPR_EQUAL:
        return "equal";
    case EXPR_NEQUAL:
        return "nequal";
    case EXPR_AND:
        return "and";
    case EXPR_OR:
        return "or";
    case EXPR_ASSIGN:
        return "assign";
    case EXPR_POSTDEC:
        return "postdec";
    case EXPR_POSTINC:
        return "postinc";

    }
}

void expr_resolve(struct expr *e)
{
    if (!e)
        return;

    if (e->kind == EXPR_IDENTIFIER) // for declared variables
    {
        e->symbol = scope_lookup(e->name);
        if (!e->symbol)
        {
            printf("resolve error: %s is not defined\n", e->name);
            resolve_error = 1;
        }
        else
        {
            if (e->symbol->kind == SYMBOL_GLOBAL)
            {
                // printf("%s resolves to global %s\n", e->symbol->name, e->symbol->name);
            }
            else if (e->symbol->kind == SYMBOL_LOCAL)
            {
                // printf("%s resolves to local %d\n", e->symbol->name, e->symbol->which);
            }
            else if (e->symbol->kind == SYMBOL_PARAM)
            {
                // printf("%s resolves to param %d\n", e->symbol->name, e->symbol->which);
            }
        }
    }
    else
    {
        expr_resolve(e->left);
        expr_resolve(e->right);
    }
}

int expr_get_length(struct expr * e){
    if(!e) return 0;
    if(e->kind == EXPR_INTEGER_LITERAL){
        return e->literal_value;
    }else{
        printf("type error: array length must be integer\n");
        return 0;
    }
}

struct expr *expr_create_name(const char *n)
{
    struct expr *e = malloc(sizeof(*e));
    e->name = strdup(n); // avoid memory leak
    e->kind = EXPR_IDENTIFIER;
    return e;
}

struct expr *expr_create_integer_literal(int c)
{
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = c;
    e->kind = EXPR_INTEGER_LITERAL;
    return e;
}

struct expr *expr_create_boolean_literal(int c)
{
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = c;
    e->kind = EXPR_BOOLEAN_LITERAL;
    return e;
}

struct expr *expr_create_char_literal(char c, int type)
{
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = c; //'a'
    e->char_type = type;
    e->kind = EXPR_CHARACTER_LITERAL;
    return e;
}

struct expr *expr_create_string_literal(const char *str)
{
    struct expr *e = malloc(sizeof(*e));
    e->string_literal = strdup(str);
    e->kind = EXPR_STRING_LITERAL;
    return e;
}

struct expr *expr_create_float_literal(const char *float_str, double float_val)
{
    struct expr *e = malloc(sizeof(*e));
    e->string_literal = strdup(float_str); // use string to print
    e->float_value = float_val;
    e->kind = EXPR_FLOAT_LITERAL;
    return e;
}

struct expr *expr_copy(struct expr *e){
    if(!e) return 0;
    if(e->kind==EXPR_INTEGER_LITERAL){
        return expr_create_integer_literal(e->literal_value);
    }else if(e->kind==EXPR_BOOLEAN_LITERAL){
        return expr_create_boolean_literal(e->literal_value);
    }else if(e->kind==EXPR_CHARACTER_LITERAL){
        return expr_create_char_literal(e->literal_value, e->char_type);
    }else if(e->kind==EXPR_STRING_LITERAL){
        return expr_create_string_literal(e->string_literal);
    }else if(e->kind==EXPR_FLOAT_LITERAL){
        return expr_create_float_literal(e->string_literal, e->float_value);
    }else if(e->kind==EXPR_IDENTIFIER){
        return expr_create_name(e->name);
    }else{
        return expr_create(e->kind, expr_copy(e->left), expr_copy(e->right));
    }

}

void expr_delete(struct expr *e)
{
    if (!e)
        return;
    expr_delete(e->left);
    expr_delete(e->right);
    free(e);
}

void expr_print(struct expr *e)
{
    if (!e)
        return;
    // printf("printing expr\n");
    if (e->kind == EXPR_ADD)
    {
        expr_print(e->left);
        printf("+");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_SUB)
    {
        expr_print(e->left);
        printf("-");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_MUL)
    {
        expr_print(e->left);
        printf("*");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_DIV)
    {
        expr_print(e->left);
        printf("/");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_MOD)
    {
        expr_print(e->left);
        printf("%%");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_EXP)
    {
        expr_print(e->left);
        printf("^");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_NOT)
    {
        printf("!");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_NEG)
    {
        printf("-");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_LESS)
    {
        expr_print(e->left);
        printf("<");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_LE)
    {
        expr_print(e->left);
        printf("<=");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_GREATER)
    {
        expr_print(e->left);
        printf(">");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_GE)
    {
        expr_print(e->left);
        printf(">=");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_EQUAL)
    {
        expr_print(e->left);
        printf("==");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_NEQUAL)
    {
        expr_print(e->left);
        printf("!=");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_AND)
    {
        expr_print(e->left);
        printf("&&");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_OR)
    {
        expr_print(e->left);
        printf("||");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_ASSIGN)
    {
        expr_print(e->left);
        printf("=");
        expr_print(e->right);
    }
    else if (e->kind == EXPR_POSTDEC)
    {
        expr_print(e->left);
        printf("--");
    }
    else if (e->kind == EXPR_POSTINC)
    {
        expr_print(e->left);
        printf("++");
    }
    else if (e->kind == EXPR_PARENTHESES)
    {
        printf("(");
        expr_print(e->left);
        printf(")");
    }
    else if (e->kind == EXPR_IDENTIFIER)
    {
        printf("%s", e->name);
    }
    else if (e->kind == EXPR_INTEGER_LITERAL)
    {
        printf("%d", e->literal_value);
    }
    else if (e->kind == EXPR_FLOAT_LITERAL)
    {
        printf("%s", e->string_literal);
        // printf(" (%f)", e->float_value);
    }
    else if (e->kind == EXPR_BOOLEAN_LITERAL)
    {
        if (e->literal_value == 0)
        {
            printf("false");
        }
        else
        {
            printf("true");
        }
    }
    else if (e->kind == EXPR_CHARACTER_LITERAL)
    {
        printf("\'");
        if (e->char_type == 1)
        { // escaped char
            printf("\\");
        }
        printf("%c", e->literal_value);
        printf("\'");
    }
    else if (e->kind == EXPR_STRING_LITERAL)
    {
        printf("%s", e->string_literal);
    }
    else if (e->kind == EXPR_ARRAY_LITERAL)
    {
        printf("{");
        if (e->left)
        {
            expr_print(e->left);
            e = e->left;
            while (e->next)
            {
                printf(", ");
                expr_print(e->next);
                e = e->next;
            }
        }
        printf("}");
    }
    else if (e->kind == EXPR_ARRAY_SUB)
    {
        expr_print(e->left);
        printf("[");
        expr_print(e->right);
        printf("]");
    }
    else if (e->kind == EXPR_FUNC)
    {
        expr_print(e->left);
        printf("(");
        if (e->right)
        {
            expr_print(e->right);
            e = e->right;
            while (e->next)
            {
                printf(", ");
                expr_print(e->next);
                e = e->next;
            }
        }
        printf(")");
    }
    else if (e->next)
    {
        printf("next\n");
        printf(", ");
        expr_print(e->next);
    }
    else
    {
        printf("Invalid expression kind\n");
    }
}
