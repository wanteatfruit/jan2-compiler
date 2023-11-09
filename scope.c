#include "scope.h"
#include "hash_table.h"
#include "stack.h"
#include <stdlib.h>

struct stack *outer = NULL; //level 0 is the top of the stack

void scope_enter(){
    struct stack *new_scope = malloc(sizeof(*new_scope));

    new_scope->table = hash_table_create(0, 0);
    if(outer == NULL){
        new_scope->level = 0;
        new_scope->total = 0; // global 
    }else{
        new_scope->level = outer->level + 1;
        new_scope->param_total = 0;
    }
    if(outer && new_scope->level>0){
        new_scope->total = outer->total; // outer is local, follow its total
    }
    new_scope->next = outer;
    outer = new_scope;
}

void scope_exit(){
    if(outer->level>1){
        outer->total = outer->next->total; // after exiting, inherit the total from the exited scope
    }
    outer = outer->next;
}

int scope_level(){
    return outer->level;
}

void scope_bind(const char *name, struct symbol *s){
    hash_table_insert(outer->table, name, s);
    if(outer->level>0){
        if(s->kind == SYMBOL_LOCAL){
            s->which = outer->total+1;
            outer->total++;
        }
        if(s->kind==SYMBOL_PARAM){
            s->which = outer->param_total+1;
            outer->param_total++;
        }

    }
}

struct symbol * scope_lookup(const char *name){
    struct stack *current = outer;
    while(current != NULL){
        struct symbol *s = hash_table_lookup(current->table, name);
        if(s != NULL){
            return s;
        }
        current = current->next;
    }
    return NULL;
}

struct symbol * scope_lookup_current(const char *name){
    return hash_table_lookup(outer->table, name);
}