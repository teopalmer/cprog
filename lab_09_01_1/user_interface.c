#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int read_matrix(matrix *A)
{
    puts("Input n, m: ");
    int ch = scanf("%d %d", &A->n, &A->m);
    if (ch != 2)
    {
        return ERROR;
    }

    puts("Input matrix: ");
    if (create_matrix(A) != OK)
        return ERROR;

    for (int i = 0; i < A->n * A->m; i++)
    {
        ch = scanf("%d", &(*((A->p) + i)));
        if (ch != 1)
            return ERROR;
    }

    return OK;
}

int print_matrix(matrix A)
{
    for (int i = 0; i < A.n; i++)
    {
        for (int j = 0; j < A.m; j++)
        {
            printf("%d ", CUR_ELEMENT);
        }
        puts("");
    }
    return OK;
}

int read_exp(int *pheta, int *gamma)
{
    puts("Enter pheta & gamma:");
    int ch = scanf("%d %d", pheta, gamma);
    if (ch != 2)
    {
        return ERROR;
    }
    return OK;
}
