#include "type.h"
#include "expr.h"
#include <stdlib.h>

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params ){
    struct type *t = malloc(sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    return t;
}

struct type * type_create_with_length( type_t kind, struct type *subtype, struct param_list *params, struct expr *length ){
    struct type *t = malloc(sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    t->length = length;
    return t;
}

int type_equals(struct type *a, struct type *b){
    if(a->kind != b->kind) return 0;
    //check sub types
    if(a->subtype && b->subtype){
        if(!type_equals(a->subtype, b->subtype)) return 0;
    }
    if(a->params && b->params){
        if(!param_list_equals(a->params, b->params)) return 0;
    }
    return 1;
}

struct type * type_copy( struct type *t ){
    if(!t) return 0;
    struct type *copy = malloc(sizeof(struct type));
    copy->kind = t->kind;
    copy->subtype = type_copy(t->subtype);
    copy->params = param_list_copy(t->params);
    copy->length = expr_copy(t->length);
    return copy;
}

void type_delete( struct type *t ){
    if(!t) return;
    param_list_delete(t->params);
    expr_delete(t->length);
    type_delete(t->subtype);
    free(t);
}

void type_print( struct type *t ){
    if(!t) return;
    if(t->subtype){
        printf("%s ", type_string(t->kind)); //need space after
    }
    else printf("%s", type_string(t->kind));
    if(t->kind == TYPE_ARRAY){
        printf("[");
        if(t->length){
            expr_print(t->length);
        }
        printf("] ");
        type_print(t->subtype);
    }else if(t->kind == TYPE_FUNCTION){
        type_print(t->subtype);
        printf("(");
        param_list_print(t->params);
        printf(")");
    }
}

char* type_string(type_t kind){
    switch(kind){
        case TYPE_BOOLEAN:
            return "boolean";
        case TYPE_CHARACTER:
            return "char";
        case TYPE_INTEGER: 
            return "integer";
        case TYPE_STRING:
            return "string";
        case TYPE_ARRAY:
            return "array";
        case TYPE_FUNCTION:
            return "function";
        case TYPE_VOID:
            return "void";
        case TYPE_FLOAT:
            return "float";
    }
}