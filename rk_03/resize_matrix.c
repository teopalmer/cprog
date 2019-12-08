#include "defines.h"
#include "resize_matrix.h"

int create_matrix(matrix_t *a)
{
    int size = a->m * a->n;
    int **pnew = calloc((size_t)a->m, sizeof(int *));

    if (pnew == NULL)
    {
        puts("ERROR");
        return memory_error;
    }

    a->p = pnew;

    for (int i = 0; i < a->m; i++)
    {
        int *k = calloc((size_t)a->n, sizeof(int));

        if (k == NULL)
            return memory_error;
        a->p[i] = k;
    }

    return ok;
}

int create_new_matrix(matrix_t *a)
{
    int **pnew = calloc((size_t)a->m, sizeof(int *));

    if (pnew == NULL)
    {
        puts("ERROR");
        return memory_error;
    }

    for (int i = 0; i < a->m; i++)
    {
        int *k = calloc((size_t)a->msize[i], sizeof(int));

        if (k == NULL)
            return memory_error;
        a->p[i] = k;
    }
    return ok;
}

int reshape_matrix(matrix_t *a, matrix_t old)
{
    int size = old.m + old.n - 1;
    a->msize = calloc((size_t)size, sizeof(int));

    for (int i = 0; i < (size/2); i++)
        a->msize[i] = i;
    for (int i = size; i > (size/2) - 1; i--)
        a->msize[i] = size - i - 1;

    for (int i = 0; i < size; i++)
        printf("%d ", a->msize[i]);

    a->m = size;

    return ok;
}

int fill_newmatrix(matrix_t *a, matrix_t old)
{
    /*for (int i = 0; i < a->m; i++)
    {
        for (int j = 0; j <= a->msize[i]; j++)
        {
            a->p[i][j] = 12;
        }
    }*/
    int c = 0;

    for (int i = 0; i < old.m; i++)
    {
        c = 0;
        for (int j = 0; j < old.n; j++)
        {
            if (i + j == old.m + a->msize[c] - 1)
            {
                a->p[0][c] = old.p[i][j];
                c++;
            }

            if (i + j == old.n + a->msize[c] - 1)
            {
                a->p[a->msize_c - 1][c] = old.p[i][j];
                c++;
            }

            if (i + j == old.m + a->msize[c] - 2)
            {
                a->p[1][c] = old.p[i][j];
                c++;
            }

            if (i + j == old.n + a->msize[c] - 2)
            {
                a->p[a->msize_c - 2][c] = old.p[i][j];
                c++;
            }

        }
    }

    return ok;
}

int delete_row(matrix_t *a, int row)
{
    int newsize = a->n * (a->m - 1);
    for (int i = row; i > a->m; i++)
        a->p[i] = a->p[i + 1];

    int **pnew = realloc(a->p, newsize * sizeof(int));
    if (pnew == NULL)
        return memory_error;

    a->p = pnew;
    (a->m)--;
    return ok;
}

