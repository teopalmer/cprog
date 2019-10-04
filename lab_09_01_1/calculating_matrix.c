#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int calc_mean_column(matrix A, int col)
{
    double mean = 0;
    for (int i = col; i < A.n * A.m - A.m; i += A.m)
        {
            mean += *(A.p + i);
        }
    mean /= AN;
    return (int)floor(mean);
}

int find_max_row(matrix A, int row)
{
    int max_el = *((A.p) + row * A.m);
    for (int *n = (A.p) + row * A.m; n < A.p + row * A.m + AM; n++)
    {
        if ((max_el) < *n)
        {
            max_el = *n;
        }
    }
    return max_el;
}

int find_max(matrix A, int *maxn, int *maxm)
{
    int max = *A.p;
    for (int i = 0; i < A.n; i++)
    {
        for (int j = 0; j < A.m; j++)
        {
            if (CUR_ELEMENT > max)
            {
                max = CUR_ELEMENT;
                *maxn = i;
                *maxm = j;
            }
        }
    }
    return OK;
}

int multiply_matrix(matrix A, matrix B, matrix *M)
{
    for (int i = 0; i < A.n; i++)
    {
        for (int j = 0; j < A.m; j++)
        {
            *((M->p) + j + i * (A.m)) = 0;
            for (int k = 0; k < A.m; k++)
                *((M->p) + j + i * (A.m)) += *((A.p) + k + i * (A.m)) * *((B.p) + j + k * (B.m));
        }
    }
    return OK;
}

int copy_matrix(matrix Old, matrix *New)
{
    for (int i = 0; i < New->m * New->n; i++)
    {
        *(New->p + i) = *(Old.p + i);
    }
    return OK;
}

void create_ematrix(matrix A, matrix *E)
{
    E->m = A.m;
    E->n = A.n;
    for (int i = 0; i < E->m * E->n; i++)
    {
        *(E->p + i) = 0;
    }

    for (int i = 0; i < E->m * E->n; i+=i)
    {
        *(E->p + i) = 1;
    }
}

int expo_matrix(matrix *A, int power)
{
    matrix AP;
    AP.m = A->m;
    AP.n = A->n;

    matrix R;
    R.m = A->m;
    R.n = A->n;

    if (create_matrix(&AP) != OK)
    {
        free(&AP);
        return ERROR;
    }

    copy_matrix(*A, &AP);
    if (create_matrix(&R) != OK)
    {
        free(&AP);
        return ERROR;
    }
    copy_matrix(*A, &R);

    if (power == 0)
    {
        create_ematrix(*A, &R);
    }

    for (int i = 0; i < power - 1; i++)
    {
        multiply_matrix(*A, AP, &R);
        copy_matrix(R, &AP);
    }
    copy_matrix(R, A);

    free(AP.p);
    free(R.p);
    return OK;
}

