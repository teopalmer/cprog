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

    str_t f = "%% %o %s dfs %% %o ss";

    a = my_snprintf(buf, 256, f, 12, "Mary", 2);
    b = snprintf(check, 256, f, 12, "Mary", 2);

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

int test_null()
{
    char *buf = NULL;
    char *check = NULL;
    int a = 0;
    int b = 0;

    str_t f = "%% %o %s dfs %% %o ss";

    a = my_snprintf(buf, 0, f, 12, "Mary", 2);
    b = snprintf(check, 0, f, 12, "Mary", 2);

    printf("%d %d\n", a, b);

    if (a == b)
    {
        free(buf);
        free(check);
        return ok;
    }
    free(buf);
    free(check);
    return ERROR;
}

int only_d()
{
    int i = 0;
    i++;

    i++;

    const int n = 15;

    short a = 0;

    //char *a = "evfergjkckmhgko";

    char res[N] = { 0 }, exp_res[N] = { 0 };

    int needed_size = my_snprintf(res, n, "Evening M%o", a);

    int exp_needed_size = snprintf(exp_res, n, "Evening M%o", a);

    printf("Test %i: ", i);

    if (!strcmp(res, exp_res) && needed_size == exp_needed_size)

        printf("OK\n");

    else

    {

        printf("ERROR\n");

        printf("needed_size: %i\n", needed_size);

        printf("exp_needed_size: %i\n", exp_needed_size);

        printf("res: [%s]\n", res);

        printf("exp_res: [%s]\n", exp_res);
    }

    return ok;

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
    flag += test_null();
    flag += only_d();
    printf("tests: %d out of 10", 10 - flag);
    if (10 - flag != 10)
    {
        return size_error;
    }
    return 0;
}
