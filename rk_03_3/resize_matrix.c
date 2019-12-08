#include "defines.h"
#include "resize_matrix.h"

int create_matrix(matrix_t *a, int size)
{
    int **pnew = calloc((size_t)a->m, sizeof(int *));

    if (pnew == NULL)
    {
        puts("ERROR");
        return memory_error;
    }

    a->p = pnew;

    for (int i = 0; i < a->m; i++)
    {
        int *k = calloc((size_t)a->m, sizeof(int));

        if (k == NULL)
            return memory_error;
        a->p[i] = k;
    }

    a->s = a->m;

    return ok;
}

int create_new_matrix(matrix_t *a, int size)
{
    a->s = size * 2 - 1;
    a->m = size;
    int **pnew = calloc((size_t)a->s, sizeof(int *));

    if (pnew == NULL)
    {
        puts("ERROR");
        return memory_error;
    }

    a->p = pnew;

    for (int i = 0; i < a->s; i++)
    {
        int *k = calloc((size_t)size, sizeof(int));

        if (k == NULL)
            return memory_error;

        a->p[i] = k;
    }

    return ok;
}


int fill_newmatrix(matrix_t *new, matrix_t old)
{
    int count = 0;
    for (int i = 0; i < old.m; i++)
    {
        for (int j = 0; j < old.m; j++)
        {
            if (i+j > new->s/2)
                count--;
            new->p[i + j][count] = old.p[i][j];
            count++;
        }
        count = 0;
    }
    return ok;
}

int clean(matrix_t *a)
{
    for (int i = 0; i < a->s; i++)
        free(a->p[i]);
    free(a->p);
    return ok;
}