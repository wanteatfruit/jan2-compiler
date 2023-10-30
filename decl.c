#include "decl.h"
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
        printf("}");
    }else{
        printf(";\n");
    }
    decl_print(d->next, indent);
    
}
