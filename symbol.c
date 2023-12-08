#include "symbol.h"
#include <string.h>
#include <stdlib.h>
struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ){
    struct symbol *s = malloc(sizeof(*s));
    s->kind = kind;
    s->type = type;
    s->name = strdup(name);
    return s;
}

const char* symbol_codegen(struct symbol *s){
    if(s->kind == SYMBOL_GLOBAL){
        return s->name;
    }
    else if(s->kind == SYMBOL_LOCAL){
        // uses abs position
        char buffer[256];
        sprintf(buffer, "-%d(%%rbp)", 8*s->which_reg);
        return strdup(buffer);
    }
    else if(s->kind == SYMBOL_PARAM){
        // uses abs position
        char buffer[256];
        sprintf(buffer, "%d(%%rbp)", 8*s->which_reg);
        return strdup(buffer);
    }
    else{
        printf("error: symbol kind not recognized\n");
        exit(1);
    }
}
