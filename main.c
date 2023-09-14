#include "encoder.h"
#include "token.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;
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

int main(int argc, char *argv[])
{
    // reading input file
    const char *input_filename = argv[2];
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Could not open file: %s\n", input_filename);
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);

    // checking arguments
    if (strcmp(argv[1], "--encode") == 0)
    {
        // encode
        char *input = malloc(input_file_size + 1);
        fread(input, 1, input_file_size, input_file);
        input[input_file_size] = '\0';
        fclose(input_file);

        char decoded[256];
        int status = string_decode(input, decoded);

        if (status != 0)
        {
            fprintf(stderr, "Error encoding string\n");
            return 1;
        }
        char encoded[512];
        status = string_encode(decoded, encoded);
        // printf("Encoded: %s\n", encoded);
    }
    else if (strcmp(argv[1], "--scan") == 0)
    {
        // scan
        yyin = input_file;
        while (1)
        {
            token_t token = yylex();
            if (token == TOKEN_EOF)
            {
                break;
            }
            else if (token == TOKEN_ERROR)
            {
                fprintf(stderr, "Scan error, invalid token: %s\n", yytext);
                return 1;
            }
            else if (token == TOKEN_INTEGER_LITERAL)
            {
                if (is_valid_int(yytext)==1)
                {
                    fprintf(stderr, "Scan error, invalid integer: %s\n", yytext);
                    return 1;
                }
                else
                {
                    printf("%s %s\n", token_names[token], yytext);
                }
            }
            else if (token == TOKEN_FLOAT_LITERAL)
            {
                if (is_valid_float(yytext)==1) // r returns 1
                {
                    fprintf(stderr, "Scan error, invalid float: %s\n", yytext);
                    return 1;
                }
                else
                {
                    printf("%s %s\n", token_names[token], yytext);
                }
            }
            else if (token == TOKEN_CHARACTER_LITERAL) //\'[\\0a-zA-Z]{1,4}\'
            {
                // regex matches both special chars (incl. \' and hex) and normal chars surrounded by single quotes,
                // check validity here
                char decoded[256];
                int status = is_valid_char(yytext, decoded);
                if (status != 0)
                {
                    fprintf(stderr, "Error encoding character\n");
                    return 1;
                }
                else
                {
                    printf("%s %s\n", token_names[token], yytext);
                }
            }
            else if (token == TOKEN_STRING_LITERAL)
            {
                // regex matches all strings surrounded by double quotes. check validity inside encoder
                char decoded[256];
                int status = is_valid_string(yytext, decoded);
                if (status != 0)
                {
                    fprintf(stderr, "Error encoding string\n");
                    return 1;
                }
                else
                {
                    printf("%s %s\n", token_names[token], decoded);
                }
            }
            else
            {
                printf("%s %s\n", token_names[token], yytext);
            }
        }
    }
    else
    {
        fprintf(stderr, "Invalid argument\n");
        return 1;
    }

    return 0;
}

//helper functions
int is_valid_int(const char *text)
{
    int64_t result = atoi(text);
    int r = sscanf(text, "%lld", &result);
    return r;
}

int is_valid_float(const char *text){
    double result = atof(text);
    int r = sscanf(text, "%lf", &result);
    return r;
}

int is_valid_char(const char *input, char *valid_chars){
    char *text = malloc(strlen(yytext) + 1);
    strcpy(text, yytext);
    text[strlen(yytext)] = '\0';
    int status = char_decode(text, valid_chars);
    return status;
}

int is_valid_string(const char *input, char *valid_chars){
    char *text = malloc(strlen(yytext) + 1);
    strcpy(text, yytext);
    text[strlen(yytext)] = '\0';
    int status = string_decode(text, valid_chars);
    return status;
}