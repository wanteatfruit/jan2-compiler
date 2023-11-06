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
    case EXPR_ADD:
        if(lt->kind!= TYPE_INTEGER || lt->kind!=TYPE_FLOAT || rt->kind!= TYPE_INTEGER || rt->kind!=TYPE_FLOAT){
            expr_print_type_error(e->kind, e, lt, rt);
            // type_error = 1;
        }
        result = type_create(TYPE_INTEGER, 0, 0);
        break;
    default:
        break;
    }

    type_delete(lt);
    type_delete(rt);

    return result;
}

void expr_print_type_error(expr_t e_type, struct expr *e, struct type *lt, struct type *rt)
{
    printf("type error: cannot ");
    type_print(lt);
    printf("( ");
    expr_print(e->left);
    printf(" ) to a ");
    type_print(rt);
    printf("( ");
    expr_print(e->right);
    printf(" )\n");
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
            exit(1);
        }
        else
        {
            if (e->symbol->kind == SYMBOL_GLOBAL)
            {
                printf("%s resolves to global ", e->symbol->name);
                expr_print(e->symbol->value);
                printf("\n");
            }
            else if (e->symbol->kind == SYMBOL_LOCAL)
            {
                printf("%s resolves to local ", e->symbol->name);
                expr_print(e->symbol->value);
                printf("\n");
            }
            else if (e->symbol->kind == SYMBOL_PARAM)
            {
                printf("%s resolves to param ", e->symbol->name);
                expr_print(e->symbol->value);
                printf("\n");
            }
        }
    }
    else
    {
        expr_resolve(e->left);
        expr_resolve(e->right);
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
