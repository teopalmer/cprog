#include "calculating_matrix.h"
#include "resizing_matrix.h"

int create_matrix(matrix *a_m)
{
    a_m->p = malloc((a_m->n) * (a_m->m) * sizeof(int));
    if (!a_m->p)
    {
        puts("Create array error");
        free(a_m->p);
        return ERROR;
    }
    return OK;
}

int resize_matrix(matrix *a_m, int fin)
{
    int *pnew = (int*)realloc(a_m->p, sizeof(pnew) * fin);
    if (pnew)
    {
        a_m->p = pnew;
        pnew = NULL;
    }
    else
    {
        return ERROR;
    }
    return OK;
}

void delete_column(matrix *a_m, int col) //столбец
{
    for (int i = col + 1; i < a_m->n * a_m->m; i += a_m->m)
    {
        for (int *j = ((a_m->p) + i); j < MAT_END; j++)
        {
            *(j - 1) = *j;
        }
        i--;
    }
    (a_m->m)--;
}

void delete_row(matrix *a_m, int row) //строка
{
    int i = row * a_m->m + 1;
    for (int n = 0; n < a_m->m; n++)
    {
        for (int *j = ((a_m->p) + i); j < MAT_END; j++)
        {
            *(j - 1) = *j;
        }
    }
    (a_m->n)--;
}

int normalize_matrix(matrix *a_m)
{
    int maxn = 0;
    int maxm = 0;
    find_max(*a_m, &maxn, &maxm);
    int fin = 0;
 
    while (a_m->n != a_m->m)
    {
        if (a_m->n > a_m->m)
        {
            delete_row(a_m, maxn);
        }
        else if (a_m->m > a_m->n)
        {
            delete_column(a_m, maxm);
        }
        find_max(*a_m, &maxn, &maxm);
    }
    fin = a_m->n * a_m->m;
    if (resize_matrix(a_m, fin) != OK)
        return ERROR;

    return OK;
}

int add_column(matrix *a_m)
{
    int newfin = a_m->m * a_m->n + a_m->n;
    int n = 0;
    if (resize_matrix(a_m, newfin) != OK)
        return ERROR;
    a_m->m ++;
    for (int *i = a_m->p + a_m->m - 1; i < MAT_END; i += a_m->m) {
        for (int *c = MAT_END; c > i; c--) {
            *c = *(c - 1);
        }
        *i = find_max_row(*a_m, n);
        n++;
    }
    return OK;
}

int add_row(matrix *a_m)
{
    int newf = a_m->m * a_m->n + a_m->m;
    if (resize_matrix(a_m, newf) != OK)
        return ERROR;
    
    a_m->n ++;
    int n = 0;

    for (int *j = MAT_END - a_m->m; j < MAT_END; j++)
    {
        *j = calc_mean_column(*a_m, n);
        n++;
    }
    return OK;
}

void equate_matrix(matrix *a_m, matrix *b_m)
{
    while (a_m->n != b_m->n)
    {
        if (a_m->n > b_m->n)
        {
            add_row(b_m);
        }
        else
            add_row(a_m);
    }
    
    while (a_m->m != b_m->m)
    {
        if (a_m->m > b_m->m)
        {
            add_column(b_m);
        }
        else
            add_column(a_m);
    }
}
