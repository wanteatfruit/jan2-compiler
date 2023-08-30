#include "encoder.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "--encode") != 0) {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        return 1;
    }
    const char *input_filename = argv[2];
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", input_filename);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);

    printf("File size: %ld\n", input_file_size);

    char *input = malloc(input_file_size + 1);
    fread(input, 1, input_file_size, input_file);
    input[input_file_size] = '\0';
    fclose(input_file);

    char decoded[256];
    printf("Input: %s\n", input);
    int status = string_decode(input, decoded);

    if (status != 0) {
        fprintf(stderr, "Error encoding string\n");
        return 1;
    }else{
        printf("Decoded success: %s\n", decoded);
    }

    char encoded[256];
    status = string_encode(decoded, encoded);
    printf("Encoded: %s\n", encoded);


    return 0;

}