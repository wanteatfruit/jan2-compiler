#ifndef TYPE_H
#define TYPE_H

#include "param_list.h"

typedef enum {
	TYPE_VOID,
	TYPE_BOOLEAN,
	TYPE_CHARACTER,
	TYPE_INTEGER,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_FUNCTION,
	TYPE_FLOAT
} type_t;

struct type {
	type_t kind;
	struct param_list *params;
	struct type *subtype;
	struct expr *length;
};

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params );
struct type * type_create_with_length( type_t kind, struct type *subtype, struct param_list *params, struct expr *length );
void          type_print( struct type *t );
char* 	   type_string( type_t kind );
int type_equals(struct type *a, struct type *b);
struct type * type_copy( struct type *t );
void type_delete( struct type *t );

#endif
