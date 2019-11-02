#include "user_interface.h"
#include "defines.h"

int scan_matrixsize(matrix_t *a)
{
    int ch = scanf("%d %d", &a->m, &a->n);
    if (ch != 2)
        return input_error;
    return ok;
}

int scan_matrix(matrix_t *a)
{
    for (int i = 0; i < a->m; i++)
    {
        for (int j = 0; j < a->n; j++)
        {
            scanf("%d", &a->p[i][j]);
        }
    }
    return ok;
}

void print_matrix(matrix_t a)
{
    for (int i = 0; i < a.m; i++)
    {
        for (int j = 0; j < a.n; j++)
        {
            printf("%d ", a.p[i][j]);
        }
        puts("");
    }
}

void print_newmatrix(matrix_t a)
{
    for (int i = 0; i < a.m; i++)
    {
        for (int j = 0; j < a.msize[i] + 1; j++)
        {
            printf("%d ", a.p[i][j]);
        }
        puts("");
    }
}