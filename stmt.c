#include "stmt.h"

stmt *stmt_create(stmt_t kind, decl *decl, expr *init_expr, expr *expr, expr *next_expr, stmt *body, stmt *else_body, stmt *next)
{
    return nullptr;
}

void stmt_print(stmt *s, int indent)
{
}
