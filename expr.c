#include "expr.h"

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}

expr *expr_create_name(const char *n)
{
    struct expr *e = malloc(sizeof(*e));
    e->name = n;
    e->kind = EXPR_IDENTIFIER;
    return e;
}

expr *expr_create_integer_literal(int c)
{
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = c;
    e->kind = EXPR_INTEGER_LITERAL;
    return e;
}

expr *expr_create_boolean_literal(int c)
{
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = c;
    e->kind = EXPR_BOOLEAN_LITERAL;
    return e;
}

expr *expr_create_char_literal(char c)
{
    struct expr *e = malloc(sizeof(*e));
    e->literal_value = c;
    e->kind = EXPR_CHARACTER_LITERAL;
    return e;
}

expr *expr_create_string_literal(const char *str)
{
    struct expr *e = malloc(sizeof(*e));
    e->string_literal = str;
    e->kind = EXPR_STRING_LITERAL;
    return e;
}

void expr_print(expr *e)
{
}
