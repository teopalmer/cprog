#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 4

enum error_codes
{
    ok = 0,
    input_error,
    memory_error
};

typedef char str_t[N];

typedef struct node
{
    str_t s;
    struct node *head;
    struct node *next;
} node_t;
