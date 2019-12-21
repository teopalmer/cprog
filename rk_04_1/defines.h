#pragma once

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef char str_t[256];

typedef struct data
{
    str_t name;
    str_t region;
    str_t okrug;
    int popul;
    int year;
} data_t;

typedef struct nodey
{
    data_t data;
    struct nodey *next;
} node_t;
