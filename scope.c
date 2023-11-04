#include "scope.h"
#include "hash_table.h"
#include "stack.h"

struct stack *top = NULL; //level 0 is the top of the stack

void scope_enter(){
    struct stack *new_scope = malloc(sizeof(*new_scope));

    new_scope->table = hash_table_create(0, 0);
    if(top == NULL){
        new_scope->level = 0;
    }else{
        new_scope->level = top->level + 1;
    }
    new_scope->next = top;
    top = new_scope;
}

void scope_exit(){
    top = top->next;
}

int scope_level(){
    return top->level;
}

void scope_bind(const char *name, struct symbol *s){
    hash_table_insert(top->table, name, s);
}

struct symbol * scope_lookup(const char *name){
    struct *stack current = top;
    while(current != NULL){
        struct symbol *s = hash_table_lookup(current->table, name);
        if(s != NULL){
            return s;
        }
        current = current->next;
    }
}

struct symbol * scope_lookup_current(const char *name){
    return hash_table_lookup(top->table, name);
}