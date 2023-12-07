#include "stmt.h"
#include "scope.h"
#include "label.h"
#include <stdlib.h>
#include "scratch.h"

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

void stmt_codegen(struct stmt *s, const char *end_label){
    if(!s) return;
    switch (s->kind)
    {
    case STMT_DECL:
        decl_codegen_local(s->decl);
        break;
    case STMT_BLOCK:
        stmt_codegen(s->body, end_label);
        break;
    case STMT_IF_ELSE:
    {
        int else_label = label_create();
        int end_if_label = label_create();
        expr_codegen(s->expr); //if
        fprintf(asm_file, "\tCMP $0, %s\n", scratch_name(s->expr->reg));//cmp if
        scratch_free(s->expr->reg);
        fprintf(asm_file, "\tJE %s\n", label_name(else_label)); //jmp to else
        stmt_codegen(s->body, end_label); //if body
        fprintf(asm_file, "\tJMP %s\n", label_name(end_if_label)); //jmp to end if
        fprintf(asm_file, "%s:\n", label_name(else_label)); //else label
        stmt_codegen(s->else_body, end_label); //else body
        fprintf(asm_file, "%s:\n", label_name(end_if_label)); //end if label
    }
        break;
    case STMT_FOR:
    {
        int top_label = label_create();
        int end_for_label = label_create();
        if(s->init_expr){ //init expr
            expr_codegen(s->init_expr);
            scratch_free(s->init_expr->reg);
        }
        fprintf(asm_file, "%s:\n", label_name(top_label)); //top label
        if(s->expr){
            expr_codegen(s->expr); //for condition
            fprintf(asm_file, "\tCMP $0, %s\n", scratch_name(s->expr->reg)); //cmp for condition
            scratch_free(s->expr->reg);
            fprintf(asm_file, "\tJE %s\n", label_name(end_for_label)); //jmp to end for
        }
        stmt_codegen(s->body, end_label); //for body
        if(s->next_expr){
            expr_codegen(s->next_expr); //next expr
            scratch_free(s->next_expr->reg);
        }
        fprintf(asm_file, "\tJMP %s\n", label_name(top_label)); //jmp to top
        fprintf(asm_file, "%s:\n", label_name(end_for_label)); //end for label
    }
    break;
    case STMT_EXPR:
        expr_codegen(s->expr);
        scratch_free(s->expr->reg);
        break;
    case STMT_PRINT:
    {
        struct expr *print = s->expr;
        while(print){
            struct type *printed_type = expr_typecheck(print);
            struct expr *printed_expr; // call lib function
            switch (printed_type->kind)
            {
                case TYPE_BOOLEAN:
                    printed_expr = expr_create(EXPR_FUNC, expr_create_name("print_boolean"), print);
                    break;
                case TYPE_INTEGER:
                    printed_expr = expr_create(EXPR_FUNC, expr_create_name("print_integer"), print);
                    break;
                case TYPE_CHARACTER:
                    printed_expr = expr_create(EXPR_FUNC, expr_create_name("print_character"), print);
                    break;
                case TYPE_STRING:
                    printed_expr = expr_create(EXPR_FUNC, expr_create_name("print_string"), print);
                    break;
            }
            expr_codegen(printed_expr);
            scratch_free(printed_expr->reg);
            print = print->next;
        }
    }
        break;
    case STMT_RETURN:
        expr_codegen(s->expr);
        fprintf(asm_file, "\tMOV %s, %%rax\n", scratch_name(s->expr->reg));
        //need to get function name
        fprintf(asm_file, "\tJMP .%s\n", end_label);
        scratch_free(s->expr->reg);
        break;
    }
    stmt_codegen(s->next, end_label);
}

void stmt_typecheck(struct stmt *s, struct type *ret_type){
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
    case STMT_FOR:
        if(s->init_expr){
            t = expr_typecheck(s->init_expr);
            type_delete(t);
        }
        if(s->expr){
            t = expr_typecheck(s->expr);
            if(t->kind != TYPE_BOOLEAN){
                printf("type error: for condition must be boolean\n");
                type_error = 1;
            }
            type_delete(t);
        }
        if(s->next_expr){
            t = expr_typecheck(s->next_expr);
            type_delete(t);
        }
        stmt_typecheck(s->body, 0);
        break;
    case STMT_IF_ELSE:
        t = expr_typecheck(s->expr);
        if(t->kind != TYPE_BOOLEAN){
            printf("type error: if condition must be boolean\n");
            type_error = 1;
        }
        type_delete(t);
        stmt_typecheck(s->body, 0);
        if(s->else_body){
            stmt_typecheck(s->else_body, 0);
        }
        break;
    case STMT_PRINT:
        if(s->expr){ // not empty print
            struct expr *print = s->expr;
            while(print){
                t = expr_typecheck(print);
                type_delete(t);
                print = print->next;
            }
        }
        break;
    case STMT_RETURN: // check if return type matches function type
        if(s->expr){
           struct expr *return_expr = s->expr;
           while(return_expr){
                t = expr_typecheck(return_expr);
                if(ret_type){
                    if(!type_equals(t, ret_type)){
                        printf("type error: return type does not match function return type\n");
                        type_error = 1;
                    }
                }
                type_delete(t);
                return_expr = return_expr->next;
           }
        }else{//return;
            if(ret_type->kind!=TYPE_VOID){
                printf("type error: return type does not match function return type\n");
                type_error = 1;
            }
        }
        break;
    case STMT_BLOCK:
        stmt_typecheck(s->body, 0);
        break;
    default:
        break;
    }
    stmt_typecheck(s->next, ret_type);
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
