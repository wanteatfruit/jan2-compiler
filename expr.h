#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include "decl.h"

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
	EXPR_ARRAY_LITERAL,
	EXPR_PARENTHESES,



	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	double float_value;
	int char_type;
	int literal_value;
	const char * string_literal;
	struct symbol *symbol;
	struct expr *next; //used for comma separated expressions lists

	int reg;
};


struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_char_literal( char c, int type );
struct expr * expr_create_string_literal( const char *str );
struct expr * expr_create_float_literal( const char *float_str, double float_val );
void expr_print( struct expr *e );
void expr_resolve( struct expr *e );
struct type * expr_typecheck( struct expr *e );
struct expr * expr_copy( struct expr *e );
void expr_delete( struct expr *e );
void expr_print_type_error(expr_t e_type, struct expr *e, struct type *lt, struct type *rt);
const char *expr_type_to_str(expr_t type);
int expr_get_length(struct expr * e);
void expr_codegen(struct expr *e);
void expr_codegen_comparison(struct expr *e);

#endif
