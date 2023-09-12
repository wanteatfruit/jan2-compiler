#include "encoder.h"
#include "token.h"
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
    "TOKEN_EOF"
};

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
            if (token == TOKEN_ERROR)
            {
                fprintf(stderr, "Error scanning file\n");
                return 1;
            }
            if(token == TOKEN_CHARACTER_LITERAL){

            }
            if (token == TOKEN_STRING_LITERAL){
                char *text = malloc(strlen(yytext) + 1);
                strcpy(text, yytext);   
                text[strlen(yytext)] = '\0';
                char decoded[256];
                int status = string_decode(text, decoded);
                if (status != 0)
                {
                    fprintf(stderr, "Error encoding string\n");
                    return 1;
                }else{
                    char encoded[512];
                    status = string_encode(decoded, encoded);
                    printf("token: %d text: %s\n",token_names[token],encoded);
                }
            }
             else {
                printf("token: %s text: %s\n",token_names[token],yytext);
            }
        }
    }else{
        fprintf(stderr, "Invalid argument\n");
        return 1;
    }

    return 0;
}