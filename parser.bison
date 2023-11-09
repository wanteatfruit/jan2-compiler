%{
    #include <stdio.h>
    #include <stdlib.h>
	#include <string.h>
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
	extern struct decl *program_result;
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

%union {
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	struct param_list *param_list;
};

%type <decl> program decl_list decl
%type <stmt> stmt_list stmt if_nest
%type <expr> expr expr_or expr_and expr_comp expr_add expr_mul expr_exp expr_unary exp_post factor arr_subscr literal arg_list arg  for_expr id
%type <type> type
%type <param_list> param_list param


%%

/* Grammar Rules */

program : decl_list TOKEN_EOF { program_result = $1;  return 0; }
	;

decl_list : decl decl_list { $1->next = $2; $$ = $1; }
	| { $$ = 0; } 
	;

stmt_list : stmt stmt_list { $1->next = $2; $$ = $1; }
	|  { $$ = 0; }
	;

stmt : decl  /* stmt decl */ { $$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0); }
	| expr TOKEN_SEMICOLON /* stmt expr */ { $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
	| TOKEN_PRINT arg_list TOKEN_SEMICOLON /* stmt print */ { $$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0, 0); }
	| TOKEN_PRINT TOKEN_SEMICOLON /* stmt empty print */ { $$ = stmt_create(STMT_PRINT, 0, 0, 0, 0, 0, 0, 0); }
	| TOKEN_RETURN expr TOKEN_SEMICOLON /* stmt return */ { $$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0, 0); }
	| TOKEN_RETURN TOKEN_SEMICOLON /* stmt empty return */ { $$ = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0); }
	| TOKEN_FOR TOKEN_L_PAREN for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_R_PAREN stmt /* stmt for */ { $$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0, 0); }
	| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN stmt /* stmt if */ { $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, 0, 0); }
	| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN if_nest TOKEN_ELSE stmt /* stmt if else */ { $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0); }
	| TOKEN_L_BRACE stmt_list TOKEN_R_BRACE /* stmt block */ { $$ = stmt_create(STMT_BLOCK,0,0,0,0,$2,0,0); }
	;

if_nest : TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN if_nest TOKEN_ELSE if_nest /* if nest */ { $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0); }
		| decl { $$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0); }
		| expr TOKEN_SEMICOLON { $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
		| TOKEN_L_BRACE stmt_list TOKEN_R_BRACE { $$ = stmt_create(STMT_BLOCK,0,0,0,0,$2,0,0);}
		| TOKEN_PRINT arg_list TOKEN_SEMICOLON /* stmt print */ { $$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0, 0); }
		| TOKEN_PRINT TOKEN_SEMICOLON /* stmt empty print */ { $$ = stmt_create(STMT_PRINT, 0, 0, 0, 0, 0, 0, 0); }
		| TOKEN_RETURN expr TOKEN_SEMICOLON /* stmt return */ { $$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0, 0); }
		| TOKEN_RETURN TOKEN_SEMICOLON /* stmt empty return */ { $$ = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0); }
		| TOKEN_FOR TOKEN_L_PAREN for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_R_PAREN if_nest /* stmt for */ { $$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0, 0); }
		;

decl : id TOKEN_COLON type TOKEN_SEMICOLON { $$ = decl_create((char *)$1->name, $3, 0, 0, 0); }
	| id TOKEN_COLON type TOKEN_ASSIGN expr TOKEN_SEMICOLON { $$ = decl_create((char *)$1->name, $3, $5, 0, 0); }
	| id TOKEN_COLON type TOKEN_ASSIGN TOKEN_L_BRACE stmt_list TOKEN_R_BRACE { $$ = decl_create((char *)$1->name, $3, 0, $6, 0); }
	;

param_list :  param   { $$ = $1; }
	| { $$ = 0;}
	;

param : id TOKEN_COLON type { $$ = param_list_create((char *)$1->name, $3, 0);}
	| id TOKEN_COLON type TOKEN_COMMA param { $$ = param_list_create((char *)$1->name, $3, $5);}
	;

arg_list : arg { $$ = $1; }
	;

arg: expr TOKEN_COMMA arg  /* multiple arg */ { $1->next = $3; $$ = $1;}
	| expr /* single arg */  { $$ = $1; }
	;


for_expr: expr { $$ = $1; }
	| { $$ = 0; }
	;


type : TOKEN_INTEGER { $$ = type_create(TYPE_INTEGER, 0, 0); }
	| TOKEN_FLOAT { $$ = type_create(TYPE_FLOAT, 0, 0); }
	| TOKEN_BOOLEAN { $$ = type_create(TYPE_BOOLEAN, 0, 0); }
	| TOKEN_CHARACTER { $$ = type_create(TYPE_CHARACTER, 0, 0); }
	| TOKEN_STRING { $$ = type_create(TYPE_STRING, 0, 0); }
	| TOKEN_VOID { $$ = type_create(TYPE_VOID, 0, 0); }
	| TOKEN_ARRAY TOKEN_L_BRACKET TOKEN_R_BRACKET type /* [] */ { $$ = type_create(TYPE_ARRAY, $4, 0); }
	| TOKEN_ARRAY TOKEN_L_BRACKET expr TOKEN_R_BRACKET type /* array [expr] integer */  { $$ = type_create_with_length(TYPE_ARRAY, $5, 0, $3); } 
	| TOKEN_FUNCTION type TOKEN_L_PAREN param_list TOKEN_R_PAREN /* function */  { $$ = type_create(TYPE_FUNCTION, $2, $4);}
	;

id : TOKEN_IDENTIFIER { $$ = expr_create_name(yytext); }
 ;

/* arthimetic expressions, printf to check for precedence */

expr : id TOKEN_ASSIGN expr { $$ = expr_create(EXPR_ASSIGN, $1, $3); }
	| arr_subscr TOKEN_ASSIGN expr { $$ = expr_create(EXPR_ASSIGN, $1, $3); }
	| expr_or { $$ = $1; }
	;

expr_or : expr_and TOKEN_OR expr_or { $$ = expr_create(EXPR_OR, $1, $3);}
	| expr_and { $$ = $1; }
	;

expr_and : expr_comp TOKEN_AND expr_and { $$ = expr_create(EXPR_AND, $1, $3);}
	| expr_comp { $$ = $1; }
	;

expr_comp : expr_add TOKEN_EQUAL expr_comp  { $$ = expr_create(EXPR_EQUAL, $1, $3);}
	| expr_add TOKEN_LESS expr_comp { $$ = expr_create(EXPR_LESS, $1, $3);}
	| expr_add TOKEN_NEQUAL expr_comp { $$ = expr_create(EXPR_NEQUAL, $1, $3);}
	| expr_add TOKEN_LE expr_comp { $$ = expr_create(EXPR_LE, $1, $3);}
	| expr_add TOKEN_GE expr_comp { $$ = expr_create(EXPR_GE, $1, $3);}
	| expr_add TOKEN_GREATER expr_comp { $$ = expr_create(EXPR_GREATER, $1, $3);}
	| expr_add { $$ = $1; }
	;

expr_add	: expr_mul TOKEN_ADD expr_add  { $$ = expr_create(EXPR_ADD, $1, $3);}
	| expr_mul TOKEN_SUB expr_add { $$ = expr_create(EXPR_SUB, $1, $3);}
	| expr_mul { $$ = $1; }
	;

expr_mul	: expr_exp TOKEN_MUL expr_mul { $$ = expr_create(EXPR_MUL, $1, $3);}
	| expr_exp TOKEN_DIV expr_mul  { $$ = expr_create(EXPR_DIV, $1, $3);}
	| expr_exp TOKEN_MOD expr_mul   { $$ = expr_create(EXPR_MOD, $1, $3);}
	| expr_exp { $$ = $1; }
	;

expr_exp	: expr_unary TOKEN_EXP expr_exp { $$ = expr_create(EXPR_EXP, $1, $3);}
			| expr_unary { $$ = $1; }
			;

expr_unary : TOKEN_SUB expr_unary  { $$ = expr_create(EXPR_NEG, 0, $2);}
			| TOKEN_NOT expr_unary   { $$ = expr_create(EXPR_NOT, 0, $2);}
			| exp_post { $$ = $1; }
			;

exp_post : factor TOKEN_POSTINC { $$ = expr_create(EXPR_POSTINC, $1, 0);}
	| factor TOKEN_POSTDEC { $$ = expr_create(EXPR_POSTDEC, $1, 0);}
	| factor { $$ = $1; }
	;

factor	: TOKEN_L_PAREN expr TOKEN_R_PAREN { $$ = expr_create(EXPR_PARENTHESES, $2, 0); }
	| arr_subscr { $$ = $1; }
	| literal { $$ = $1; }
	| id { $$ = $1;}
	| id TOKEN_L_PAREN arg_list TOKEN_R_PAREN { $$ = expr_create(EXPR_FUNC, $1, $3);}
	| id TOKEN_L_PAREN TOKEN_R_PAREN { $$ = expr_create(EXPR_FUNC, $1, 0); }  /* function call without args */
	; 

arr_subscr : factor TOKEN_L_BRACKET expr TOKEN_R_BRACKET { $$ = expr_create(EXPR_ARRAY_SUB, $1, $3);}
	;
		 

literal : TOKEN_INTEGER_LITERAL { $$ = expr_create_integer_literal(atoi(yytext)); }
	| TOKEN_FLOAT_LITERAL { $$ = expr_create_float_literal(yytext, atof(yytext)); }
	| TOKEN_CHARACTER_LITERAL {
			if(strlen(yytext) == 3){ // 'a'
 				$$ = expr_create_char_literal(yytext[1], 0); 
			}else if(strlen(yytext) == 4){ // '\n'
				$$ = expr_create_char_literal(yytext[2], 1);
			}
		 } /* only one character */
	| TOKEN_STRING_LITERAL { $$ = expr_create_string_literal(yytext); }
	| TOKEN_TRUE { $$ = expr_create_boolean_literal(1); }
	| TOKEN_FALSE { $$ = expr_create_boolean_literal(0); }
	| TOKEN_L_BRACE arg_list TOKEN_R_BRACE { $$ = expr_create(EXPR_ARRAY_LITERAL, $2, 0); }
	;


%%

int yyerror(char *s) {
    printf("parse error: %s\n", s);
    return 1;
}
