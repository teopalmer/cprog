#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int read_matrix(matrix *a_m)
{
    puts("Input n, m: ");
    int ch = scanf("%d %d", &a_m->n, &a_m->m);
    if (ch != 2 || a_m->m <= 0 || a_m->n <= 0)
    {
        return ERROR;
    }

    puts("Input matrix: ");
    if (create_matrix(a_m) != OK)
        return ERROR;

    for (int i = 0; i < a_m->n * a_m->m; i++)
    {
        ch = scanf("%d", &(*((a_m->p) + i)));
        if (ch != 1)
        {
            free(a_m->p);
            return ERROR;
        }
    }

    return OK;
}

int print_matrix(matrix a_m)
{
    for (int i = 0; i < a_m.n; i++)
    {
        for (int j = 0; j < a_m.m; j++)
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
