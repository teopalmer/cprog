#include <stdio.h>
#include "defines.h"
#include "snprintf.h"
#include "str_funcs.h"

int test_buf_0()
{
    char *buf = calloc(300, sizeof(char));
    char *check = calloc(300, sizeof(char));

    str_t f = "%o Honey %o %ohno khd%o";

    my_sprintf(buf, 0, f, 1, 2, 13, 10394);
    snprintf(check, 0, f, 1, 2, 13, 10394);

    if (strcmp(buf, check) == 0)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int test_buf_o()
{
    char *buf = malloc(256 * sizeof(char));
    char *check = malloc(256 * sizeof(char));

    str_t f = "%o Honey %o %ohno khd%o";

    my_sprintf(buf, 12, f, 1, 2, 13, 109);
    snprintf(check, 12, f, 1, 2, 13, 109);

    if (strcmp(buf, check) == 0)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int test_buf_s()
{
    char *buf = malloc(256 * sizeof(char));
    char *check = malloc(256 * sizeof(char));

    str_t f = "%s Honey %s %shno khd%s";

    my_sprintf(buf, 12, f, "one", "two", "three", "four");
    snprintf(check, 12, f, "one", "two", "three", "four");

    if (strcmp(buf, check) == 0)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int test_o()
{
    char *buf = malloc(256 * sizeof(char));
    char *check = malloc(256 * sizeof(char));

    str_t f = "%o Honey %o %ohno khd%o";

    my_sprintf(buf, 256, f, 1, 2, 13, 109);
    snprintf(check, 256, f, 1, 2, 13, 109);

    if (strcmp(buf, check) == 0)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int test_hd()
{
    char *buf = malloc(256 * sizeof(char));
    char *check = malloc(256 * sizeof(char));

    str_t f = "%o Honey %o %ohno khd%o";

    my_sprintf(buf, 256, f, 1, 2, 13, 10334);
    snprintf(check, 256, f, 1, 2, 13, 10334);

    if (strcmp(buf, check) == 0)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int test_s()
{
    char *buf = malloc(256 * sizeof(char));
    char *check = malloc(256 * sizeof(char));

    str_t f = "%s Honey %s %shno khd%s";

    my_sprintf(buf, 256, f, "one", "two", "three", "four");
    snprintf(check, 256, f, "one", "two", "three", "four");

    if (strcmp(buf, check) == 0)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int main() {
    int flag = 0;
    flag += test_buf_0();
    flag += test_buf_o();
    flag += test_buf_s();
    flag += test_hd();
    flag += test_o();
    flag += test_s();
    printf("tests: %d out of 6", 6 - flag);
    if (flag > 0)
    {
        return size_error;
    }
    return 0;
}
