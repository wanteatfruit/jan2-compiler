#ifndef STACK_H
#define STACK_H

#include "hash_table.h"

struct stack {
    struct hash_table *table;
    struct stack *next;
    int level;
    int total; // tracking number of local variables
    int param_total; // tracking number of parameters
};

#endif