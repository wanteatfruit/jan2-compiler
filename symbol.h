
#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"

typedef enum {
	SYMBOL_LOCAL,
	SYMBOL_PARAM,
	SYMBOL_GLOBAL
} symbol_t;

struct symbol {
	symbol_t kind;
	struct type *type;
	char *name;
	int which;
	int which_reg;

	int is_prototype; // for functions
	//for literal values
	struct expr *value;
};

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name );
const char* symbol_codegen(struct symbol *s);
#endif
