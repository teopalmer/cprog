#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int64_t calc_mean_column(matrix a_m, int64_t col)
{
    double mean = 0;
    for (int64_t i = col; i < a_m.n * a_m.m - a_m.m; i += a_m.m)
    {
        mean += *(a_m.p + i);
    }
    mean /= AN;
    return (int64_t)floor(mean);
}

int64_t find_max_row(matrix a_m, int64_t row)
{
    int64_t max_el = *((a_m.p) + row * a_m.m);
    for (int64_t *n = (a_m.p) + row * a_m.m; n < a_m.p + row * a_m.m + AM; n++)
    {
        if ((max_el) < *n)
        {
            max_el = *n;
        }
    }
    return max_el;
}

int64_t find_max(matrix a_m, int64_t *maxn, int64_t *maxm)
{
    int64_t max = *a_m.p;
    for (int64_t i = 0; i < a_m.n; i++)
    {
        for (int64_t j = 0; j < a_m.m; j++)
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

int64_t multiply_matrix(matrix a_m, matrix b_m, matrix *m_m)
{
    for (int64_t i = 0; i < a_m.n; i++)
    {
        for (int64_t j = 0; j < a_m.m; j++)
        {
            *((m_m->p) + j + i * (a_m.m)) = 0;
            for (int64_t k = 0; k < a_m.m; k++)
                *((m_m->p) + j + i * (a_m.m)) += *((a_m.p) + k + i * (a_m.m)) * *((b_m.p) + j + k * (b_m.m));
        }
    }
    return OK;
}

int64_t copy_matrix(matrix old, matrix *newm)
{
    for (int64_t i = 0; i < newm->m * newm->n; i++)
    {
        *(newm->p + i) = *(old.p + i);
    }
    return OK;
}

void create_ematrix(matrix *e_m)
{
    for (int64_t i = 0; i < e_m->m * e_m->n; i++)
    {
        *(e_m->p + i) = 0;
    }

    for (int64_t i = 0; i < e_m->m * e_m->n; i += e_m->m + 1)
    {
        *(e_m->p + i) = 1;
    }
}

int64_t expo_matrix(matrix *a_m, int64_t power)
{
    matrix ap_m;
    ap_m.m = a_m->m;
    ap_m.n = a_m->n;

    matrix r_m;
    r_m.m = a_m->m;
    r_m.n = a_m->n;
    
    if (power < 0)
        return ERROR;

    if (create_matrix(&ap_m) != OK)
    {
        free(ap_m.p);
        return ERROR;
    }

    copy_matrix(*a_m, &ap_m);
    if (create_matrix(&r_m) != OK)
    {
        free(ap_m.p);
        return ERROR;
    }
    copy_matrix(*a_m, &r_m);

    if (power == 0)
    {
        create_ematrix(&r_m);
    }

    for (int64_t i = 0; i < power - 1; i++)
    {
        multiply_matrix(*a_m, ap_m, &r_m);
        copy_matrix(r_m, &ap_m);
    }
    copy_matrix(r_m, a_m);

    free(ap_m.p);
    free(r_m.p);
    return OK;
}

