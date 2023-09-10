#include "encoder.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

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
        }
    }else{
        fprintf(stderr, "Invalid argument\n");
        return 1;
    }

    return 0;
}