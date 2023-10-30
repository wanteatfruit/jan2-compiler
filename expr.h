#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_MOD,
	EXPR_ASSIGN,
	EXPR_OR,
	EXPR_AND,
	EXPR_EQUAL,
	EXPR_NEQUAL,
	EXPR_LESS,
	EXPR_GREATER,
	EXPR_LE,
	EXPR_GE,
	EXPR_EXP,
	EXPR_NOT,
	EXPR_NEG,
	EXPR_POSTINC,
	EXPR_POSTDEC,
	EXPR_FUNC,
	EXPR_ARRAY_SUB,
	EXPR_IDENTIFIER,
	EXPR_INTEGER_LITERAL,
	EXPR_CHARACTER_LITERAL,
	EXPR_STRING_LITERAL,
	EXPR_BOOLEAN_LITERAL,
	EXPR_FLOAT_LITERAL,
	EXPR_ARRAY_LITERAL



	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	int literal_value;
	const char * string_literal;
	struct symbol *symbol;
	struct expr *next; //used for function arguments
	struct expr *inside; //used for parenthesis
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_char_literal( char c );
struct expr * expr_create_string_literal( const char *str );
struct expr * expr_create_float_literal( float f );
struct expr * expr_create_paren( expr_t kind, struct expr *inside);
void expr_print( struct expr *e );

#endif
