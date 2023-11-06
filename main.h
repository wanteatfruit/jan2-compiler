#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
char *token_names[] = {
    "TOKEN_ARRAY",
    "TOKEN_BOOLEAN",
    "TOKEN_CHARACTER",
    "TOKEN_FLOAT",
    "TOKEN_FUNCTION",
    "TOKEN_INTEGER",
    "TOKEN_STRING",
    "TOKEN_VOID",
    "TOKEN_INTEGER_LITERAL",
    "TOKEN_CHARACTER_LITERAL",
    "TOKEN_STRING_LITERAL",
    "TOKEN_FLOAT_LITERAL",
    "TOKEN_ELSE",
    "TOKEN_FALSE",
    "TOKEN_FOR",
    "TOKEN_IF",
    "TOKEN_PRINT",
    "TOKEN_RETURN",
    "TOKEN_TRUE",
    "TOKEN_WHILE",
    "TOKEN_AUTO",
    "TOKEN_IDENTIFIER",
    "TOKEN_L_PAREN",
    "TOKEN_R_PAREN",
    "TOKEN_L_BRACKET",
    "TOKEN_R_BRACKET",
    "TOKEN_L_BRACE",
    "TOKEN_R_BRACE",
    "TOKEN_POSTINC",
    "TOKEN_POSTDEC",
    "TOKEN_NEG",
    "TOKEN_NOT",
    "TOKEN_EXP",
    "TOKEN_MUL",
    "TOKEN_DIV",
    "TOKEN_MOD",
    "TOKEN_ADD",
    "TOKEN_SUB",
    "TOKEN_LESS",
    "TOKEN_LE",
    "TOKEN_GE",
    "TOKEN_GREATER",
    "TOKEN_EQUAL",
    "TOKEN_NEQUAL",
    "TOKEN_AND",
    "TOKEN_OR",
    "TOKEN_ASSIGN",
    "TOKEN_SEMICOLON",
    "TOKEN_COLON",
    "TOKEN_COMMA",
    "TOKEN_BACKSLASH",
    "TOKEN_C_COMMENT",
    "TOKEN_CPP_COMMENT",
    "TOKEN_ERROR",
    "TOKEN_EOF"};


//helper functions
int is_overflow_int(const char *text);
int is_overflow_float(const char *text);

int is_valid_char(const char *text, char *valid_chars);
int is_valid_string(const char *text, char *valid_chars);

int scan_tokens(FILE *input_file);
int parse(FILE *input_file);
int resolve();

#endif