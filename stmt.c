#include "stmt.h"
#include "scope.h"
#include <stdlib.h>

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next )
{
    struct stmt *s = malloc(sizeof(*s));
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
    return s;
}

void stmt_typecheck(struct stmt *s){
    if(!s) return;
    struct type *t;
    switch (s->kind)
    {
    case STMT_DECL:
        decl_typecheck(s->decl);
        break;
    case STMT_EXPR:
        t = expr_typecheck(s->expr);
        type_delete(t);
        break;
    case STMT_IF_ELSE:
        t = expr_typecheck(s->expr);
        if(t->kind != TYPE_BOOLEAN){
            printf("type error: if condition must be boolean\n");
            type_error = 1;
        }
        type_delete(t);
        stmt_typecheck(s->body);
        if(s->else_body){
            stmt_typecheck(s->else_body);
        }
        break;
    case STMT_BLOCK:
        stmt_typecheck(s->body);
        break;
    default:
        break;
    }
}

void stmt_resolve(struct stmt *s)
{
    if(!s) return;
    // resolve according to kind

    if(s->kind == STMT_DECL){
        decl_resolve(s->decl);
    }else if(s->kind == STMT_EXPR){
        expr_resolve(s->expr);
    }else if(s->kind == STMT_IF_ELSE){
        expr_resolve(s->expr); // if condition
        scope_enter(); // if body scope
        stmt_resolve(s->body); // if body
        scope_exit(); // exit if body scope
        if(s->else_body){
            scope_enter(); // else body scope
            stmt_resolve(s->else_body); // else body
            scope_exit(); // exit else body scope
        }
    }else if(s->kind == STMT_FOR){
        expr_resolve(s->init_expr); 
        expr_resolve(s->expr); 
        expr_resolve(s->next_expr); 
        scope_enter(); // for body scope
        stmt_resolve(s->body); // for body
        scope_exit(); // exit for body scope
    }else if(s->kind == STMT_PRINT){
        struct expr *print = s->expr;
        while(print){
            expr_resolve(print);
            print = print->next;
        }
    }else if(s->kind == STMT_RETURN){
        expr_resolve(s->expr);
    }else if(s->kind == STMT_BLOCK){
        scope_enter(); // block scope
        stmt_resolve(s->body); // block body
        scope_exit();
    }else{
        printf("Invalid statement kind\n");
    }
    stmt_resolve(s->next);

}

void stmt_print(struct stmt *s, int indent)
{
    if(!s) return;
    // print according to kind
    if(s->kind == STMT_DECL){
        decl_print(s->decl, indent);
    }else if(s->kind == STMT_EXPR){
        print_indent(indent);
        expr_print(s->expr);
        printf(";\n");
    }else if(s->kind == STMT_IF_ELSE){
        print_indent(indent);
        printf("if(");
        expr_print(s->expr);
        printf(") {\n");
        stmt_print(s->body, indent+1); //if body
        print_indent(indent);
        printf("}");
        if(s->else_body){
            printf(" else {\n");
            // print_indent(indent);
            stmt_print(s->else_body, indent+1); //else body
            print_indent(indent);
            printf("}\n");
        }else{
            printf("\n");
        }
    }else if(s->kind == STMT_FOR){
        print_indent(indent);
        printf("for(");
        expr_print(s->init_expr);
        printf("; ");
        expr_print(s->expr);
        printf("; ");
        expr_print(s->next_expr);
        printf(") {\n");
        stmt_print(s->body, indent+1);
        print_indent(indent);
        printf("}\n");
    }else if(s->kind == STMT_PRINT){
        print_indent(indent);
        printf("print ");
        if(s->expr){
            struct expr *print = s->expr;
            while(print){
                expr_print(print);
                if(print->next){
                    printf(", ");
                }
                print = print->next;
            }
        }
        printf(";\n");
    }else if(s->kind == STMT_RETURN){
        print_indent(indent);
        printf("return ");
        expr_print(s->expr);
        printf(";\n");
    }else if(s->kind == STMT_BLOCK){
        print_indent(indent);
        printf("{\n");
        stmt_print(s->body, indent+1);
        print_indent(indent);
        printf("}\n");
    }else{
        printf("Invalid statement kind\n");
    }
    stmt_print(s->next, indent);
}

void print_indent(int indent){
    for(int i = 0; i < indent; i++){
        printf("\t");
    }
}
