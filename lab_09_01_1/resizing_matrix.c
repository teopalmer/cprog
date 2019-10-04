#include "calculating_matrix.h"
#include "resizing_matrix.h"

int create_matrix(matrix *A)
{
    A->p = malloc(A->n * A->m * sizeof(int));
    if (!A->p)
    {
        puts("Create array error");
        free(A->p);
        return ERROR;
    }
    return OK;
}

int resize_matrix(matrix *A, int fin)
{
    int *pnew = (int*)realloc(A->p, sizeof(pnew) * fin);
    if (pnew)
    {
        A->p = pnew;
        pnew = NULL;
    }
    else
    {
        return ERROR;
    }
    return OK;
}

void delete_column(matrix *A, int col) //столбец
{
    for (int i = col + 1; i < A->n * A->m; i += A->m)
    {
        for (int *j = ((A->p) + i); j < MAT_END; j++)
        {
            *(j - 1) = *j;
        }
        i--;
    }
    (A->m)--;
}

void delete_row(matrix *A, int row) //строка
{
    int i = row * A->m + 1;
    for (int n = 0; n < A->m; n++)
    {
        for (int *j = ((A->p) + i); j < MAT_END; j++)
        {
            *(j - 1) = *j;
        }
    }
    (A->n)--;
}

int normalize_matrix(matrix *A)
{
    int maxn = 0;
    int maxm = 0;
    find_max(*A, &maxn, &maxm);
    int diff = abs(A->n - A->m);
    int fin = A->n * A->m;

    for (int i = 0; i < diff; i++)
    {
        if (A->n > A->m)
        {
            delete_row(A, maxn);
            fin -= A->n;
        }
        else if (A->m > A->n)
        {
            delete_column(A, maxm);
            fin -= A->m;
        }
        find_max(*A, &maxn, &maxm);
    }
    if (!resize_matrix(A, fin))
        return ERROR;
    return OK;
}

void add_column(matrix *A)
{
    int newfin = A->m * A->n + A->n;
    int n = 0;
    resize_matrix(A, newfin);
    A->m ++;
    for (int *i = A->p + A->m - 1; i < MAT_END; i += A->m) {
        for (int *c = MAT_END; c > i; c--) {
            *c = *(c - 1);
        }
        *i = find_max_row(*A, n);
        n++;
    }
}

void add_row(matrix *A)
{
    int newf = A->m * A->n + A->m;
    resize_matrix(A, newf);
    A->n ++;
    int n = 0;

    for (int *j = MAT_END - A->m; j < MAT_END; j++)
    {
        *j = calc_mean_column(*A, n);
        n++;
    }
}

void equate_matrix(matrix *A, matrix *B)
{
    while (A->m != B->m)
    {
        if (A->m > B->m)
        {
            add_row(B);
        }
        else
        {
            add_row(A);
        }
    }
    while (A->n != B->n)
    {
        if (A->n > B->n)
        {
            add_column(B);
        }
        else
        {
            add_column(A);
        }
    }
}
