#include "expr.h"
#include <string.h>
#include <stdlib.h>

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->left = left;
    e->right = right;
    // e->next = next; //chaining exprs in comma separated lists
    return e;
}

struct expr *expr_create_name(const char *n)
{
    struct expr *e = malloc(sizeof(*e));
    e->name = strdup(n);
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

struct expr *expr_create_char_literal(char c)
{
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = c;
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

struct expr *expr_create_float_literal(float f){
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = f;
    e->kind = EXPR_FLOAT_LITERAL;
    return e;
}

void expr_print(struct expr *e)
{
    if(!e) return;
    // printf("printing expr\n");
    if(e->kind == EXPR_ADD){
        expr_print(e->left);
        printf(" + ");
        expr_print(e->right);
    }else if(e->kind == EXPR_SUB){
        expr_print(e->left);
        printf(" - ");
        expr_print(e->right);
    }else if(e->kind == EXPR_MUL){
        expr_print(e->left);
        printf(" * ");
        expr_print(e->right);
    }else if(e->kind == EXPR_DIV){
        expr_print(e->left);
        printf(" / ");
        expr_print(e->right);
    }else if(e->kind == EXPR_MOD){
        expr_print(e->left);
        printf(" %% ");
        expr_print(e->right);
    }else if(e->kind == EXPR_EXP){
        expr_print(e->left);
        printf(" ^ ");
        expr_print(e->right);
    }else if(e->kind == EXPR_NOT){
        printf("!");
        expr_print(e->right);
    }else if(e->kind == EXPR_NEG){
        printf("-");
        expr_print(e->right);
    }else if(e->kind == EXPR_LESS){
        expr_print(e->left);
        printf(" < ");
        expr_print(e->right);
    }else if(e->kind == EXPR_LE){
        expr_print(e->left);
        printf(" <= ");
        expr_print(e->right);
    }else if(e->kind == EXPR_GREATER){
        expr_print(e->left);
        printf(" > ");
        expr_print(e->right);
    }else if(e->kind == EXPR_GE){
        expr_print(e->left);
        printf(" >= ");
        expr_print(e->right);
    }else if(e->kind == EXPR_EQUAL){
        expr_print(e->left);
        printf(" == ");
        expr_print(e->right);
    }else if(e->kind == EXPR_NEQUAL){
        expr_print(e->left);
        printf(" != ");
        expr_print(e->right);
    }else if(e->kind == EXPR_AND){
        expr_print(e->left);
        printf(" && ");
        expr_print(e->right);
    }else if(e->kind == EXPR_OR){
        expr_print(e->left);
        printf(" || ");
        expr_print(e->right);
    }else if(e->kind == EXPR_ASSIGN){
        expr_print(e->left);
        printf(" = ");
        expr_print(e->right);
    }else if(e->kind == EXPR_IDENTIFIER){
        // printf("printing identifier\n");
        printf("%s", e->name);
    }else if(e->kind == EXPR_INTEGER_LITERAL){
        printf("%d", e->literal_value);
    }else if(e->kind == EXPR_BOOLEAN_LITERAL){
        if(e->literal_value == 0){
            printf("false");
        }else{
            printf("true");
        }
    }else if(e->kind == EXPR_CHARACTER_LITERAL){
        printf("\'");
        printf("%c", (char) e->literal_value);
        printf("\'");
    }else if(e->kind == EXPR_STRING_LITERAL){
        printf("%s", e->string_literal);
    }else if(e->kind == EXPR_ARRAY){
        expr_print(e->left);
        printf("[");
        expr_print(e->right);
        printf("]");
    }else if(e->kind == EXPR_FUNC){
        expr_print(e->left);
        printf("(");
        expr_print(e->right);
        printf(")");
    }else{
        printf("Invalid expression kind\n");
    }


}
