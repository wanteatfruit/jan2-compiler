#ifndef TOKEN_H
#define TOKEN_H

typedef enum
{
    // Types
    TOKEN_ARRAY,
    TOKEN_BOOLEAN,
    TOKEN_CHARACTER,
    TOKEN_FLOAT,
    TOKEN_FUNCTION,
    TOKEN_INTEGER,
    TOKEN_STRING,
    TOKEN_VOID,
    // Literals
    TOKEN_INTEGER_LITERAL,   
    TOKEN_CHARACTER_LITERAL, 
    TOKEN_STRING_LITERAL,
    // Keywords
    TOKEN_ELSE,
    TOKEN_FALSE,
    TOKEN_FOR,
    TOKEN_IF,
    TOKEN_PRINT,
    TOKEN_RETURN,
    TOKEN_TRUE,
    TOKEN_WHILE,
    TOKEN_AUTO,
    // Identifiers
    TOKEN_IDENTIFIER,
    // Expressions
    TOKEN_L_PAREN,
    TOKEN_R_PAREN,
    TOKEN_L_BRACKET,
    TOKEN_R_BRACKET,
    TOKEN_L_BRACE,
    TOKEN_R_BRACE,
    TOKEN_POSTINC,
    TOKEN_POSTDEC,
    TOKEN_NEG,
    TOKEN_NOT,
    TOKEN_EXP,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_MOD,
    TOKEN_ADD,
    TOKEN_SUB,
    TOKEN_LESS,
    TOKEN_LE,
    TOKEN_GE,
    TOKEN_GREATER,
    TOKEN_EQUAL,
    TOKEN_NEQUAL,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_ASSIGN,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_BACKSLASH,

    // Everything else
    TOKEN_ERROR,
    TOKEN_EOF
} token_t;

#endif
