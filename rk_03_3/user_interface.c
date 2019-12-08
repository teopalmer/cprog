#include "user_interface.h"
#include "defines.h"

int scan_size(matrix_t *a)
{
    int ch = scanf("%d", &a->m);
    if (ch == 1)
        return ok;
    return input_error;
}

int scan_matrix(matrix_t *a)
{
    int ch = 0;
    for (int i = 0; i < a->m; i++)
    {
        for (int j = 0; j < a->m; j++)
        {
            ch = scanf("%d", &a->p[i][j]);
            if (ch != 1)
                return input_error;
        }
    }
    return ok;
}

int scan_new_matrix(matrix_t *a)
{
    int s = a->m * 2 - 1;
    for (int i = 0; i < a->m; i++)
    {
        for (int j = 0; j < a->m; j++)
        {
            a->p[i][j] = 3;
        }
    }
    return ok;
}

void print_matrix(matrix_t a)
{
    for (int i = 0; i < a.m; i++) {
        for (int j = 0; j < a.m; j++) {
            printf("%d ", a.p[i][j]);
        }
        puts("");
    }
    puts("");
}

void print_new_matrix(matrix_t a)
{
    int s = a.m * 2 - 1;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            printf("%d ", a.p[i][j]);
        }
        puts("");
    }
}