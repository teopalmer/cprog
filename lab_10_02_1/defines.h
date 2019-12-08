#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef LAB_10_DEFINES_H

#define N 256
#define ADD 1
#define DELETE -1
#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y))

enum error_codes
{
    ok = 0,
    input_error,
    deletion_error,
    memory_error,
    article_nothing,
};

typedef char str_t[N];

typedef struct
{
    char *article;
    long int size_a;
    char *name;
    long int size_n;
    int count;
} item_t;

#define LAB_10_DEFINES_H

#endif //LAB_10_DEFINES_H
