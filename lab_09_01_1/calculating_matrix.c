#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int calc_mean_column(matrix a_m, int col)
{
    double mean = 0;
    for (int i = col; i < a_m.n * a_m.m - a_m.m; i += a_m.m)
    {
        mean += *(a_m.p + i);
    }
    mean /= AN;
    return (int)floor(mean);
}

int find_max_row(matrix a_m, int row)
{
    int max_el = *((a_m.p) + row * a_m.m);
    for (int *n = (a_m.p) + row * a_m.m; n < a_m.p + row * a_m.m + AM; n++)
    {
        if ((max_el) < *n)
        {
            max_el = *n;
        }
    }
    return max_el;
}

int find_max(matrix a_m, int *maxn, int *maxm)
{
    int max = *a_m.p;
    for (int i = 0; i < a_m.n; i++)
    {
        for (int j = 0; j < a_m.m; j++)
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

int multiply_matrix(matrix a_m, matrix b_m, matrix *m_m)
{
    for (int i = 0; i < a_m.n; i++)
    {
        for (int j = 0; j < a_m.m; j++)
        {
            *((m_m->p) + j + i * (a_m.m)) = 0;
            for (int k = 0; k < a_m.m; k++)
                *((m_m->p) + j + i * (a_m.m)) += *((a_m.p) + k + i * (a_m.m)) * *((b_m.p) + j + k * (b_m.m));
        }
    }
    return OK;
}

int copy_matrix(matrix old, matrix *newm)
{
    for (int i = 0; i < newm->m * newm->n; i++)
    {
        *(newm->p + i) = *(old.p + i);
    }
    return OK;
}

void create_ematrix(matrix a_m, matrix *e_m)
{
    e_m->m = a_m.m;
    e_m->n = a_m.n;
    for (int i = 0; i < e_m->m * e_m->n; i++)
    {
        *(e_m->p + i) = 0;
    }

    for (int i = 0; i < e_m->m * e_m->n; i += i)
    {
        *(e_m->p + i) = 1;
        i++;
    }
}

int expo_matrix(matrix *a_m, int power)
{
    matrix ap_m;
    ap_m.m = a_m->m;
    ap_m.n = a_m->n;

    matrix R_m;
    R_m.m = a_m->m;
    R_m.n = a_m->n;
    
    if (power < 0)
        return ERROR;

    if (create_matrix(&ap_m) != OK)
    {
        free(ap_m.p);
        return ERROR;
    }

    copy_matrix(*a_m, &ap_m);
    if (create_matrix(&R_m) != OK)
    {
        free(ap_m.p);
        return ERROR;
    }
    copy_matrix(*a_m, &R_m);

    if (power == 0)
    {
        create_ematrix(*a_m, &R_m);
    }

    for (int i = 0; i < power - 1; i++)
    {
        multiply_matrix(*a_m, ap_m, &R_m);
        copy_matrix(R_m, &ap_m);
    }
    copy_matrix(R_m, a_m);

    free(ap_m.p);
    free(R_m.p);
    return OK;
}

