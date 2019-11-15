#include <stdlib.h>
#include <stdio.h>

#ifndef RK_03_DEFINES_H

typedef struct
{
    int **p;
    int m;
    int n;
    int *msize;
    int msize_c;

} matrix_t;

enum error_codes
{
    ok = 0,
    input_error,
    memory_error
};

#define RK_03_DEFINES_H

#endif //RK_03_DEFINES_H
