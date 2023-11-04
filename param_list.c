#include "param_list.h"
#include "scope.h"
#include <stdlib.h>

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
    struct param_list *p = malloc(sizeof(*p));
    p->name = name;
    p->type = type;
    p->next = next;
    return p;
}

void param_list_print( struct param_list *a ){
    if(!a) return;
    printf("%s: ", a->name);
    type_print(a->type);
    while(a->next){
        printf(", ");
        a = a->next;
        printf("%s: ", a->name);
        type_print(a->type);
    }
}

void param_list_resolve( struct param_list *a ){
    if(!a) return;
    if(scope_lookup_current(a->name)){
        printf("resolve error: %s is already defined in current scope\n", a->name);
        return;
    } else{
        a->symbol = symbol_create(SYMBOL_PARAM, a->type, a->name);
        scope_bind(a->name, a->symbol);
    }
    param_list_resolve(a->next);
}