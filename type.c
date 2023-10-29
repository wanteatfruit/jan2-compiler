#include "type.h"

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params ){
    struct type *t = malloc(sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    return t;
}

void type_print( struct type *t ){
    if(!t) return;
    printf("%s", type_string(t));
    if(t->kind == TYPE_ARRAY){
        printf("[");
        // type_print(t->subtype);
        printf("]");
    }else if(t=>kind == TYPE_FUNCTION){
        printf("(");
        // param_list_print(t->params);
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
    }
}