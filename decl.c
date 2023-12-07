#include "decl.h"
#include "scope.h"
#include "scratch.h"
#include <stdlib.h>
#include <string.h>



struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ){
    struct decl *d = malloc(sizeof(*d));
    d->name = strdup(name);
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_codegen_local(struct decl *d){
    if(!d) return;
    if(d->value){
        expr_codegen(d->value);
        //function not allowed
        switch(d->type->kind){
            case TYPE_INTEGER:
                fprintf(asm_file, "\tMOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
                scratch_free(d->value->reg);
                break;
            case TYPE_ARRAY:
                fprintf(asm_file, "\tMOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
                scratch_free(d->value->reg);
                break;
            case TYPE_BOOLEAN:
                fprintf(asm_file, "\tMOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
                scratch_free(d->value->reg);
                break;
            case TYPE_CHARACTER:
                fprintf(asm_file, "\tMOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
                scratch_free(d->value->reg);
                break;
            case TYPE_STRING:
                fprintf(asm_file, "\tMOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
                scratch_free(d->value->reg);
                break;
            default:
                printf("error: declaration local code gen not found type\n");
                exit(1);
        }
        decl_codegen_local(d->next);
    }
}

void decl_codegen_global(struct decl *d){
    if(!d) return;

    switch(d->type->kind){
        //print a data for every global decl
        case TYPE_INTEGER:
            fprintf(asm_file, ".data\n");
            fprintf(asm_file, "%s:\t.quad %d\n", d->name, d->value->literal_value);
            break;
        case TYPE_ARRAY:
            fprintf(asm_file, ".data\n");
            {
                int label_num = label_create();
                fprintf(asm_file, "%s:\n", label_name(label_num));
                struct expr *array_literal = d->value->left;
                while(array_literal){
                    fprintf(asm_file, "\t.quad %d\n", array_literal->literal_value);
                    array_literal = array_literal->next;
                }
            
            fprintf(asm_file, ".globl %s\n%s:\n", d->name, d->name);
            fprintf(asm_file, "\t.quad %s\n", label_name(label_num));
            }
            break;
        case TYPE_BOOLEAN:
            fprintf(asm_file, ".data\n");
            fprintf(asm_file, "%s:\t.quad %d\n", d->name, d->value->literal_value);
            break;
        case TYPE_CHARACTER:
            fprintf(asm_file, ".data\n");
            fprintf(asm_file, "%s:\t.quad %d\n", d->name, d->value->literal_value);
            break;
        case TYPE_STRING:
            fprintf(asm_file, ".data\n");
            fprintf(asm_file, "%s:\t.string %s\n", d->name, d->value->string_literal);
            break;
       
        case TYPE_FUNCTION:
            if(d->code){ // definition included
                //preamble
                fprintf(asm_file, ".text\n.globl %s\n%s:\n", d->name, d->name);
                fprintf(asm_file, "\tPUSHQ %%rbp\n");
                fprintf(asm_file, "\tMOVQ %%rsp, %%rbp\n");
                //check args
                int num_args = 0;
                struct param_list *p = d->type->params;
                //push args
                const char *arg_regs[] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
                while(p){
                    if(num_args > 5){
                        printf("error: too many arguments for function %s\n", d->name);
                        exit(1);
                    }
                    fprintf(asm_file, "\tPUSHQ %%%s\n", arg_regs[num_args]);
                    num_args++;
                    p = p->next;
                }
                //allocate local vars (current space for 10)
                fprintf(asm_file, "\tSUBQ $40, %%rsp\n");
                //push callee saved regs
                fprintf(asm_file, "\tPUSHQ %%rbx\n\tPUSHQ %%r12\n\tPUSHQ %%r13\n\tPUSHQ %%r14\n\tPUSHQ %%r15\n");
                //body
                char func_label[256]; //need pass return label to stmt_codegen
                sprintf(func_label, "%s_epilogue", d->name);
                stmt_codegen(d->code, func_label);
                //func epilogue
                fprintf(asm_file, ".%s:\n", func_label);
                fprintf(asm_file, "\tPOPQ %%r15\n\tPOPQ %%r14\n\tPOPQ %%r13\n\tPOPQ %%r12\n\tPOPQ %%rbx\n");
                fprintf(asm_file, "\tMOVQ %%rbp, %%rsp\n");
                fprintf(asm_file, "\tPOPQ %%rbp\n");
                fprintf(asm_file, "\tRET\n");
            }else{ // prototype
                fprintf(asm_file, ".text\n.globl %s\n", d->name);
            }
    }
    decl_codegen_global(d->next);
}

void decl_typecheck(struct decl *d){
    if(!d) return;
    
    if(d->value) {
        struct type *t;
        t = expr_typecheck(d->value);
        if(!type_equals(t,d->symbol->type)) {
            printf("type error: cannot assign ");
            type_print(t);
            printf(" (%s)", d->name);
            printf(" to ");
            type_print(d->symbol->type);
            printf("\n");
            type_error = 1;
        }
        if(d->type->kind == TYPE_ARRAY){ // check array length
            struct expr *decl_length_expr = d->type->length;
            int decl_length = expr_get_length(decl_length_expr);
            struct expr *array_literal = d->value->left;
            int literal_length = 0;
            while(array_literal){
                literal_length++;
                array_literal = array_literal->next;
            }
            if(decl_length != literal_length){
                printf("type error: array literal (%s) length does not match declaration\n", d->name);
                type_error = 1;
            }

        }
    }
    if(d->type->kind==TYPE_FUNCTION &&  d->code) {
        stmt_typecheck(d->code, d->type->subtype);
    }

    decl_typecheck(d->next);
}

void decl_resolve( struct decl *d ){
    if(!d) return;
    struct symbol *existing_symbol = scope_lookup_current(d->name);
    symbol_t kind = scope_level() > 0 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;
    d->symbol = symbol_create(kind, d->type, d->name);

    if(d->value){ // a: integer = 1;
        if(existing_symbol && kind == existing_symbol->kind){
            printf("resolve error: duplicate declaration of %s\n", d->name);
            resolve_error = 1;
        }
        expr_resolve(d->value);
        scope_bind(d->name, d->symbol);
        d->symbol->value = d->value;
    }else if(!d->value && d->type->kind != TYPE_FUNCTION){ // a: integer;
        if(existing_symbol && kind == existing_symbol->kind){
            printf("resolve error: duplicate declaration of %s\n", d->name);
            resolve_error = 1;
        }
        scope_bind(d->name, d->symbol);
    }

    if(d->type->kind == TYPE_FUNCTION && d->code){ // func with code
        if(existing_symbol && existing_symbol->is_prototype){ // func prototype exists, should be same type
            if(!type_equals(d->type, existing_symbol->type)){
                printf("resolve error: function %s does not match prototype\n", d->name);
                resolve_error = 1;
            }
        }
        if(existing_symbol && !existing_symbol->is_prototype){ // dup func definition
            printf("resolve error: duplicate definition of %s\n", d->name);
            resolve_error = 1;
        }
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
        scope_bind(d->name, d->symbol);
    }
    if(d->type->kind == TYPE_FUNCTION && !d->code){ // func prototype
        if(existing_symbol && existing_symbol->is_prototype){ // dup prototype
            if(!type_equals(d->type, existing_symbol->type)){
                printf("resolve error: redeclared prototype %s does not match prototype\n", d->name);
                resolve_error = 1;
            }
        }
        d->symbol->is_prototype = 1;
        scope_enter();
        param_list_resolve(d->type->params);
        scope_exit();
        scope_bind(d->name, d->symbol);
    }

    decl_resolve(d->next);
}

void decl_print( struct decl *d, int indent ){
    if(!d) return;
    // print indent
    for(int i = 0; i < indent; i++){
        printf("\t");
    }
    printf("%s: ", d->name);
    type_print(d->type);
    if(d->value){ // decl with value
        printf(" = ");
        expr_print(d->value);
        printf(";\n");
    }else if(d->code){
        printf(" = {\n");
        stmt_print(d->code, indent+1);
        printf("}\n");
    }else{
        printf(";\n");
    }
    decl_print(d->next, indent);
    
}
