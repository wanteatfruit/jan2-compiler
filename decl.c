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

void decl_resolve( struct decl *d ){
    if(!d) return;
    // resolve type
    type_resolve(d->type);
    // resolve value
    expr_resolve(d->value);
    // resolve code
    if(d->code){
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
    }
    // resolve next
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
