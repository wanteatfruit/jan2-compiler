#ifndef MAIN_H
#define MAIN_H

//helper functions
int is_overflow_int(const char *text);
int is_overflow_float(const char *text);

int is_valid_char(const char *text, char *valid_chars);
int is_valid_string(const char *text, char *valid_chars);

#endif