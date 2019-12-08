#ifndef UNTITLED_DEFINES_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define N 256
#define ERROR 1
#define SHORTMIN -32768
#define SHORTMAX 32767

typedef char str_t[N];

enum error_codes
{
    ok = 0,
    memory_error,
    size_error,
    numb_of_args,
    invalid_format,
};
#define UNTITLED_DEFINES_H

#endif //UNTITLED_DEFINES_H
