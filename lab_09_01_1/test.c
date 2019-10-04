#include <stdio.h>
#include <stdlib.h>
#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

void fill_square_matrix(matrix *t, int case_num)
{
    switch (case_num)
    {
        default:
            break;
        case 1:
            *t->p = 1;
            *(t->p + 1) = 2;
            *(t->p + 2) = 3;
            *(t->p + 3) = 4;
            break;
        case 2:
            *t->p = 1;
            *(t->p + 1) = 1;
            *(t->p + 2) = 1;
            *(t->p + 3) = 1;
            break;
        case 3:
            *t->p = -1;
            *(t->p + 1) = -2;
            *(t->p + 2) = -3;
            *(t->p + 3) = -4;
            break;
        case 11:
            *t->p = 1;
            *(t->p + 1) = 0;
            *(t->p + 2) = 0;
            *(t->p + 3) = 1;
            break;
        case 22:
            *t->p = 1;
            *(t->p + 1) = 1;
            *(t->p + 2) = 1;
            *(t->p + 3) = 1;
            break;
        case 33:
            *t->p = 7;
            *(t->p + 1) = 10;
            *(t->p + 2) = 15;
            *(t->p + 3) = 22;
            break;
    }
}

void fill_matrix(matrix *t, int case_num)
{
    switch (case_num)
    {
        default:
            break;
        case 1:
            *t->p = 1;
            *(t->p + 1) = 2;
            *(t->p + 2) = 3;
            *(t->p + 3) = 4;
            *(t->p + 4) = 5;
            *(t->p + 5) = 6;
            break;
    }
}

int compare_matrices(matrix a, matrix b)
{
    if (a.n != b.n || a.m != b.m)
        return FAILED;
    for (int i = 0; i < a.m * a.n; i++)
    {
        if (*(a.p + i) != *(b.p + i))
        {
            return FAILED;
        }
    }
    return PASSED;
}

int test_expo_zero(matrix *t, matrix *tres)
{
    fill_square_matrix(t, 1);
    fill_square_matrix(tres, 11);
    expo_matrix(t, 0);
    return (compare_matrices(*t, *tres));
}

int test_expo_one(matrix *t, matrix *tres)
{
    fill_square_matrix(t, 2);
    fill_square_matrix(tres, 22);
    expo_matrix(t, 1);
    return (compare_matrices(*t, *tres));
}

int test_expo_ord(matrix *t, matrix *tres)
{
    fill_square_matrix(t, 3);
    fill_square_matrix(tres, 33);
    expo_matrix(t, 2);
    return (compare_matrices(*t, *tres));
}

int test_find_max_ord(matrix *t)
{
    int maxn, maxm;
    fill_square_matrix(t, 1);
    find_max(*t, &maxn, &maxm);
    if (maxn != 0 || maxm != 1)
        return FAILED;
    return PASSED;
}

int test_find_max_same(matrix *t)
{
    int maxn, maxm;
    fill_square_matrix(t, 2);
    find_max(*t, &maxn, &maxm);
    if (maxn != 0 || maxm != 0)
        return FAILED;
    return PASSED;
}

int test_calc_mean(matrix *t)
{
    fill_square_matrix(t, 1);
    int c = calc_mean_column(*t, 0);
    if (c != 2)
        return FAILED;
    return PASSED;
}

int test_find_max_row(matrix *t)
{
    fill_square_matrix(t, 3);
    int c = find_max_row(*t, 0);
    if (c != 2)
        return FAILED;
    return PASSED;
}

int test_multiply_ord(matrix *a, matrix *b)
{
    matrix m;
    m.n = 2;
    m.m = 2;
    create_matrix(&m);
    fill_square_matrix(a, 1);
    fill_square_matrix(b, 11);
    multiply_matrix(*a, *b, &m);

    return compare_matrices(*b, m);
}

int test_delete_column(matrix *t, matrix *tres)
{
    t->m = 3;
    fill_matrix(t, 1);
    fill_square_matrix(tres, 1);
    delete_column(t, 2);
    return compare_matrices(*t, *tres);
}

int main()
{
    matrix t;
    matrix tres;
    int c = 0;

    t.n = 2;
    t.m = 2;
    tres.n = 2;
    tres.m = 2;

    create_matrix(&t);
    create_matrix(&tres);

    c += test_find_max_same(&t);
    c += test_find_max_same(&t);
    //c += test_find_max_same(&t);
    //c += test_multiply_ord(&t, &tres);
    //c += test_find_max_row(&t);
    //c += test_find_max_ord(&t);
    //c += test_expo_zero(&t, &tres);
    //c += test_expo_ord(&t, &tres);
    //c += test_expo_one(&t, &tres);

    free(t.p);
    free(tres.p);

    return OK;
}
