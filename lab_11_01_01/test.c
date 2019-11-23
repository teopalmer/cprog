#include <stdio.h>
#include "defines.h"
#include "snprintf.h"
#include "str_funcs.h"

int test_buf_0()
{
    char *buf = calloc(300, sizeof(char));
    char *check = calloc(300, sizeof(char));
    int a = 0;
    int b = 0;

    str_t f = "%o Honey %o %ohno khd%o";

    a = my_snprintf(buf, 0, f, 1, 2, 13, 10394);
    b = snprintf(check, 0, f, 1, 2, 13, 10394);

    if (strcmp(buf, check) == 0 && a == b)
    {
        free(buf);
        free(check);
        return ok;
    }
    
    free(buf);
    free(check);
    return ERROR;
}

int test_percent()
{
    char *buf = calloc(300, sizeof(char));
    char *check = calloc(300, sizeof(char));
    int a = 0;
    int b = 0;

    str_t f = "Honehak akdjak %% akshbak %% aksdj";

    a = my_snprintf(buf, 256, f, 1);
    b = snprintf(check, 256, f, 1);

    if (strcmp(buf, check) == 0 && a == b)
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
    int a = 0;
    int b = 0;

    str_t f = "%o Honey %o %ohno khd%o";

    a = my_snprintf(buf, 12, f, 1, 2, 13, 109);
    b = snprintf(check, 12, f, 1, 2, 13, 109);

    if (strcmp(buf, check) == 0 && a == b)
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
    int a = 0;
    int b = 0;

    str_t f = "%s Honey %s %shno khd%s";

    a = my_snprintf(buf, 12, f, "one", "two", "three", "four");
    b = snprintf(check, 12, f, "one", "two", "three", "four");

    if (strcmp(buf, check) == 0 && a == b)
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
    int a = 0;
    int b = 0;

    str_t f = "%o Honey %o %ohno khd%o";

    a = my_snprintf(buf, 256, f, 1, 2, 13, 109);
    b = snprintf(check, 256, f, 1, 2, 13, 109);

    if (strcmp(buf, check) == 0 && a == b)
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
    int a = 0;
    int b = 0;

    str_t f = "%o Honey %o %ohno khd%o";

    a = my_snprintf(buf, 256, f, 1, 2, 13, 10334);
    b = snprintf(check, 256, f, 1, 2, 13, 10334);

    if (strcmp(buf, check) == 0 && a == b)
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
    int a = 0;
    int b = 0;

    str_t f = "%s Honey %s %shno khd%s";

    a = my_snprintf(buf, 256, f, "one", "two", "three", "four");
    b = snprintf(check, 256, f, "one", "two", "three", "four");

    if (strcmp(buf, check) == 0 && a == b)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int test_all_random()
{
    char *buf = malloc(256 * sizeof(char));
    char *check = malloc(256 * sizeof(char));
    int a = 0;
    int b = 0;

    str_t f = "%s: %o %hd,\n      %o, %hd, %s";

    a = my_snprintf(buf, 256, f, "Mary", 12, 32, 3, 23, "Kane");
    b = snprintf(check, 256, f, "Mary", 12, 32, 3, 23, "Kane");

    //printf("%d %d\n", a, b);
    //printf("%s\n%s\n", buf, check);

    if (strcmp(buf, check) == 0 && a == b)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int test_all_another()
{
    char *buf = malloc(256 * sizeof(char));
    char *check = malloc(256 * sizeof(char));
    int a = 0;
    int b = 0;

    str_t f = "%%%%%%%?%";

    a = my_snprintf(buf, 256, f);
    b = snprintf(check, 256, f);

    if (strcmp(buf, check) == 0 && a == b)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int main()
{
    int flag = 0;
    flag += test_buf_0();
    flag += test_buf_o();
    flag += test_buf_s();
    flag += test_hd();
    flag += test_o();
    flag += test_s();
    flag += test_percent();
    flag += test_all_random();
    flag += test_all_another();
    printf("tests: %d out of 9", 9 - flag);
    /*if (flag > 0)
    {
        return size_error;
    }*/
    return 0;
}
