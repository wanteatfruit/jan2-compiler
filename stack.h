#ifndef STACK_H
#define STACK_H

#include "hash_table.h"

struct stack {
    struct hash_table *table;
    struct stack *next;
    int level;
};

#endif