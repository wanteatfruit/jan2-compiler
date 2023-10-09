%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    extern char *yytext;
    extern int yylex();
    extern int yyerror( char *str );
	extern FILE *yyin;
%}

%token TOKEN_ARRAY
%token TOKEN_BOOLEAN
%token TOKEN_CHARACTER
%token TOKEN_FLOAT
%token TOKEN_FUNCTION
%token TOKEN_INTEGER
%token TOKEN_STRING
%token TOKEN_VOID
%token TOKEN_INTEGER_LITERAL   
%token TOKEN_CHARACTER_LITERAL 
%token TOKEN_STRING_LITERAL
%token TOKEN_FLOAT_LITERAL
%token TOKEN_ELSE
%token TOKEN_FALSE
%token TOKEN_FOR
%token TOKEN_IF
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_TRUE
%token TOKEN_WHILE
%token TOKEN_AUTO
%token TOKEN_IDENTIFIER
%token TOKEN_L_PAREN
%token TOKEN_R_PAREN
%token TOKEN_L_BRACKET
%token TOKEN_R_BRACKET
%token TOKEN_L_BRACE
%token TOKEN_R_BRACE
%token TOKEN_POSTINC
%token TOKEN_POSTDEC
%token TOKEN_NEG
%token TOKEN_NOT
%token TOKEN_EXP
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_MOD
%token TOKEN_ADD
%token TOKEN_SUB
%token TOKEN_LESS
%token TOKEN_LE
%token TOKEN_GE
%token TOKEN_GREATER
%token TOKEN_EQUAL
%token TOKEN_NEQUAL
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_ASSIGN
%token TOKEN_SEMICOLON
%token TOKEN_COLON
%token TOKEN_COMMA
%token TOKEN_BACKSLASH
%token TOKEN_C_COMMENT
%token TOKEN_CPP_COMMENT
%token TOKEN_ERROR
%token TOKEN_EOF

%%

/* Grammar Rules */

program : stmt_list { return 0; }
	;

stmt_list : stmt stmt_list
	| stmt
	;

stmt : decl TOKEN_SEMICOLON { printf("stmt decl\n"); }
	| expr TOKEN_SEMICOLON { printf("stmt expr\n"); }
	| TOKEN_PRINT print_list TOKEN_SEMICOLON { printf("stmt print\n"); }
	| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN stmt { printf("stmt if\n"); }
	| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN if_nest TOKEN_ELSE stmt { printf("stmt if else\n"); }
	| TOKEN_L_BRACE stmt_list TOKEN_R_BRACE { printf("stmt block\n"); }
	;

if_nest : TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN if_nest TOKEN_ELSE if_nest { printf("if nest\n"); }
		| decl TOKEN_SEMICOLON
		| expr TOKEN_SEMICOLON
		| TOKEN_L_BRACE stmt_list TOKEN_R_BRACE
		;

decl : id TOKEN_COLON type { printf("decl without value\n"); }
	| id TOKEN_COLON type TOKEN_ASSIGN expr { printf("decl with value\n"); }
	| id TOKEN_COLON type idx type { printf("array decl\n"); }
	| id TOKEN_COLON type idx type TOKEN_ASSIGN brac_list  { printf("array decl with value\n"); }
	| id TOKEN_COLON TOKEN_FUNCTION type arg_list { printf("function prototype decl\n"); }
	;

brac_list : TOKEN_L_BRACE brac_list TOKEN_R_BRACE
	| expr TOKEN_COMMA brac_list
	| expr
	;


arg_list : arg TOKEN_COMMA arg_list
	| TOKEN_L_PAREN arg_list TOKEN_R_PAREN
	| arg
	;

arg : id TOKEN_COLON type
	;

print_list : expr TOKEN_COMMA print_list
	| expr
	|
	;

idx : TOKEN_L_BRACKET expr TOKEN_R_BRACKET
	;

type : TOKEN_INTEGER
	| TOKEN_FLOAT
	| TOKEN_BOOLEAN
	| TOKEN_CHARACTER
	| TOKEN_STRING
	| TOKEN_VOID
	| TOKEN_ARRAY
	| TOKEN_FUNCTION
	;

id : TOKEN_IDENTIFIER;

/* arthimetic expressions, printf to check for precedence */

expr : id TOKEN_ASSIGN expr
	| expr_or
	;

expr_or : expr_and TOKEN_OR expr_or { printf("or\n"); }
	| expr_and
	;

expr_and : expr_comp TOKEN_AND expr_and { printf("and\n"); }
	| expr_comp
	;

expr_comp : expr_add TOKEN_EQUAL expr_comp { printf("comparison\n"); }
	| expr_add TOKEN_LESS expr_comp
	| expr_add TOKEN_NEQUAL expr_comp
	| expr_add TOKEN_LE expr_comp
	| expr_add TOKEN_GE expr_comp
	| expr_add TOKEN_GREATER expr_comp
	| expr_add
	;

expr_add	: expr_mul TOKEN_ADD expr_add  { printf("add\n"); }
	| expr_mul TOKEN_SUB expr_add
	| expr_mul
	;

expr_mul	: expr_exp TOKEN_MUL expr_mul { printf("mul\n"); }
	| expr_exp TOKEN_DIV expr_mul 
	| expr_exp TOKEN_MOD expr_mul  
	| expr_exp
	;

expr_exp	: expr_unary TOKEN_EXP expr_exp { printf("exp\n"); }
			| expr_unary
			;

expr_unary : TOKEN_NEG expr_unary   { printf("neg\n"); }
			| TOKEN_NOT expr_unary   { printf("not\n"); }
			| exp_post
			;

exp_post : factor TOKEN_POSTINC { printf("postinc\n"); }
	| factor TOKEN_POSTDEC
	| factor
	;

factor	: TOKEN_L_PAREN expr TOKEN_R_PAREN
	| literal
	| id
	;

literal : TOKEN_INTEGER_LITERAL
	| TOKEN_FLOAT_LITERAL
	| TOKEN_CHARACTER_LITERAL
	| TOKEN_STRING_LITERAL
	| TOKEN_TRUE
	| TOKEN_FALSE
	;


%%

int yyerror(char *s) {
    printf("parse error: %s\n", s);
    return 1;
}
