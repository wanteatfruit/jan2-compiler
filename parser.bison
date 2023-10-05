%{
    #include <stdio.h>
    #include <stdlib.h>
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

program : expr TOKEN_SEMICOLON;

expr : expr TOKEN_ADD term
     | expr TOKEN_SUB term
     | term;

term : term TOKEN_MUL factor
        | term TOKEN_DIV factor
        | term TOKEN_MOD factor
        | factor;

factor : TOKEN_SUB factor
       | TOKEN_L_PAREN expr TOKEN_R_PAREN
       | TOKEN_INTEGER_LITERAL
       ;

%%

int yyerror(char *s) {
    printf("parse error: %s\n", s);
    return 1;
}
