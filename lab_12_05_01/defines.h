#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 5

enum error_codes
{
    ok = 0,
    input_error,
    memory_error
};

typedef char str_t[N];

typedef struct nodey
{
    str_t s;
    struct nodey *head;
    struct nodey *next;
} node_t;
