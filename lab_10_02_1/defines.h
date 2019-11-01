#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LAB_10_DEFINES_H

#define N 256
#define ADD 1
#define DELETE -1
#define max(X, Y)  ((X) > (Y) ? (X) : (Y))

enum error_codes
{
    OK = 0,
    INPUT_ERROR,
    DELETION_ERROR,
    MEMORY_ERROR,
    ARTICLE_NOTHING,
};

typedef char str_t[N];

typedef struct
{
    char *article;
    long int sizeA;
    char *name;
    long int sizeN;
    int count;
} item_t;

#define LAB_10_DEFINES_H

#endif //LAB_10_DEFINES_H
