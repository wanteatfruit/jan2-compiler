
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include "label.h"
#include <stdio.h>
#include <stdlib.h>

struct decl {
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
};

extern int resolve_error;
extern int type_error;
extern FILE *asm_file;

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next );
void decl_print( struct decl *d, int indent );
void decl_typecheck( struct decl *d );
void decl_resolve( struct decl *d );
void decl_codegen_global( struct decl *d );
void decl_codegen_local( struct decl *d );
#endif


