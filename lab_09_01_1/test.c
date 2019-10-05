#include <stdio.h>
#include <stdlib.h>
#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

void fill_square_matrix(matrix *t, int x1, int x2, int x3, int x4)
{
    *t->p = x1;
    *(t->p + 1) = x2;
    *(t->p + 2) = x3;
    *(t->p + 3) = x4;
}

void fill_2x3_matrix(matrix *t, int x1, int x2, int x3, int x4, int x5, int x6)
{
    *t->p = x1;
    *(t->p + 1) = x2;
    *(t->p + 2) = x3;
    *(t->p + 3) = x4;
    *(t->p + 4) = x5;
    *(t->p + 5) = x6;
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

int test_normalize_ord_col(matrix *t, matrix *tres)
{
    t->m = 3;
    fill_square_matrix(tres, 1, 2, 4, 5);
    fill_2x3_matrix(t, 1, 2, 3, 4, 5, 6);
    normalize_matrix(t);
    int log = compare_matrices(*t, *tres);
    t->m = 2;
    return log;
}

int test_normalize_ord_row(matrix *t, matrix *tres)
{
    t->n = 3;
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_2x3_matrix(t, 1, 2, 3, 4, 5, 6);
    normalize_matrix(t);
    int log = compare_matrices(*t, *tres);
    t->n = 2;
    return log;
}

int test_normalize_same(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_square_matrix(t, 1, 2, 3, 4);
    normalize_matrix(t);
    int log = compare_matrices(*t, *tres);
    return log;
}

int test_expo_zero(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 1, 0, 0, 1);
    fill_square_matrix(t, 1, 2, 3, 4);
    expo_matrix(t, 0);
    return compare_matrices(*t, *tres);
}

int test_expo_one(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_square_matrix(t, 1, 2, 3, 4);
    expo_matrix(t, 1);
    return compare_matrices(*t, *tres);
}

int test_expo_more(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 7, 10, 15, 22);
    fill_square_matrix(t, 1, 2, 3, 4);
    expo_matrix(t, 2);
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

    c += test_normalize_ord_col(&t, &tres);
    c += test_normalize_ord_row(&t, &tres);
    c += test_normalize_same(&t, &tres);
    c += test_expo_zero(&t, &tres);
    c += test_expo_one(&t, &tres);
    c += test_expo_more(&t, &tres);

    printf("c = %d\n", c);

    free(t.p);
    free(tres.p);

    return OK;
}
