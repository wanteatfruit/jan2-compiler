#include "param_list.h"
#include <stdlib.h>

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
    struct param_list *p = malloc(sizeof(*p));
    p->name = name;
    p->type = type;
    p->next = next;
    return p;
}

void param_list_print( struct param_list *a ){
    printf("%s: ", a->name);
    type_print(a->type);
    while(a->next){
        printf(", ");
        a = a->next;
        printf("%s: ", a->name);
        type_print(a->type);
    }
}