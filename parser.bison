%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
	#include "decl.h"
	#include "stmt.h"
	#include "expr.h"
	#include "type.h"
	#include "param_list.h"

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

program : decl_list TOKEN_EOF {  return 0; }
	;

decl_list : decl decl_list
	| 
	;

stmt_list : stmt stmt_list
	| 
	;

stmt : decl  /* stmt decl */
	| expr TOKEN_SEMICOLON /* stmt expr */
	| TOKEN_PRINT arg_list TOKEN_SEMICOLON /* stmt print */
	| TOKEN_PRINT TOKEN_SEMICOLON
	| TOKEN_RETURN expr TOKEN_SEMICOLON /* stmt return */
	| TOKEN_RETURN TOKEN_SEMICOLON /* stmt empty return */
	| TOKEN_FOR TOKEN_L_PAREN for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_R_PAREN stmt /* stmt for */
	| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN stmt /* stmt if */
	| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN if_nest TOKEN_ELSE stmt /* stmt if else */
	| TOKEN_L_BRACE stmt_list TOKEN_R_BRACE /* stmt block */
	| TOKEN_C_COMMENT
	| TOKEN_CPP_COMMENT
	;

if_nest : TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN if_nest TOKEN_ELSE if_nest /* if nest */
		| decl 
		| expr TOKEN_SEMICOLON
		| TOKEN_L_BRACE stmt_list TOKEN_R_BRACE
		| TOKEN_PRINT arg_list TOKEN_SEMICOLON /* stmt print */
		| TOKEN_PRINT TOKEN_SEMICOLON
		| TOKEN_RETURN expr TOKEN_SEMICOLON /* stmt return */
		| TOKEN_RETURN TOKEN_SEMICOLON /* stmt empty return */
		| TOKEN_FOR TOKEN_L_PAREN for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_R_PAREN if_nest /* stmt for */
		| TOKEN_C_COMMENT
		| TOKEN_CPP_COMMENT
		;

decl : id TOKEN_COLON type TOKEN_SEMICOLON /* literal, array, function without assignment  */
	| id TOKEN_COLON type TOKEN_ASSIGN expr TOKEN_SEMICOLON /* literal with assignment */
	| id TOKEN_COLON type TOKEN_ASSIGN TOKEN_L_BRACE brace_list TOKEN_R_BRACE TOKEN_SEMICOLON  /* array with assignment */
	| id TOKEN_COLON type TOKEN_ASSIGN TOKEN_L_BRACE stmt_list TOKEN_R_BRACE {printf("main");}  /* func with assignment */
	;

param_list :  param  
	| 
	;

param : id TOKEN_COLON type /* single param */
	| id TOKEN_COLON type TOKEN_COMMA param /* multiple param */
	;

brace_list : brace
	| TOKEN_L_BRACE brace_list TOKEN_R_BRACE TOKEN_COMMA brace_list
	| TOKEN_L_BRACE brace_list TOKEN_R_BRACE

brace: expr TOKEN_COMMA brace
	| expr
	;

arg_list : arg 
	;

arg: expr TOKEN_COMMA arg  /* multiple arg */
	| expr /* single arg */
	;


for_expr: expr 
	|
	;


type : TOKEN_INTEGER 
	| TOKEN_FLOAT
	| TOKEN_BOOLEAN
	| TOKEN_CHARACTER
	| TOKEN_STRING
	| TOKEN_VOID
	| TOKEN_ARRAY TOKEN_L_BRACKET TOKEN_R_BRACKET type /* [] */
	| TOKEN_ARRAY TOKEN_L_BRACKET expr TOKEN_R_BRACKET type /* array [expr] integer */ 
	| TOKEN_FUNCTION type TOKEN_L_PAREN param_list TOKEN_R_PAREN /* function */ 
	;

id : TOKEN_IDENTIFIER;

/* arthimetic expressions, printf to check for precedence */

expr : id TOKEN_ASSIGN expr
	| arr_subscr TOKEN_ASSIGN expr
	| expr_or
	;

expr_or : expr_and TOKEN_OR expr_or /* or */
	| expr_and
	;

expr_and : expr_comp TOKEN_AND expr_and /* and */
	| expr_comp
	;

expr_comp : expr_add TOKEN_EQUAL expr_comp /* comparison */
	| expr_add TOKEN_LESS expr_comp
	| expr_add TOKEN_NEQUAL expr_comp
	| expr_add TOKEN_LE expr_comp
	| expr_add TOKEN_GE expr_comp
	| expr_add TOKEN_GREATER expr_comp
	| expr_add
	;

expr_add	: expr_mul TOKEN_ADD expr_add  /* add */
	| expr_mul TOKEN_SUB expr_add
	| expr_mul
	;

expr_mul	: expr_exp TOKEN_MUL expr_mul /* mul */
	| expr_exp TOKEN_DIV expr_mul 
	| expr_exp TOKEN_MOD expr_mul  
	| expr_exp
	;

expr_exp	: expr_unary TOKEN_EXP expr_exp /* exp */
			| expr_unary
			;

expr_unary : TOKEN_SUB expr_unary   /* neg */
			| TOKEN_NOT expr_unary   /* not */
			| TOKEN_ADD expr_unary  /* plus */
			| exp_post
			;

exp_post : factor TOKEN_POSTINC /* postinc */
	| factor TOKEN_POSTDEC
	| factor
	;

factor	: TOKEN_L_PAREN expr TOKEN_R_PAREN
	| arr_subscr
	| literal
	| id
	| id TOKEN_L_PAREN arg_list TOKEN_R_PAREN 
	| id TOKEN_L_PAREN TOKEN_R_PAREN  /* function call without args */
	; 

arr_subscr : factor TOKEN_L_BRACKET expr TOKEN_R_BRACKET; /* array subscription */
		 

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
