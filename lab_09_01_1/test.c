#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

void fill_square_matrix(matrix *t, int64_t x1, int64_t x2, int64_t x3, int64_t x4)
{
    *t->p = x1;
    *(t->p + 1) = x2;
    *(t->p + 2) = x3;
    *(t->p + 3) = x4;
}

void fill_2x3_matrix(matrix *t, int64_t x1, int64_t x2, int64_t x3, int64_t x4, int64_t x5, int64_t x6)
{
    *t->p = x1;
    *(t->p + 1) = x2;
    *(t->p + 2) = x3;
    *(t->p + 3) = x4;
    *(t->p + 4) = x5;
    *(t->p + 5) = x6;
}

void fill_3x3_matrix(matrix *t, int64_t x1, int64_t x2, int64_t x3, int64_t x4, int64_t x5, int64_t x6, int64_t x7, int64_t x8, int64_t x9)
{
    *t->p = x1;
    *(t->p + 1) = x2;
    *(t->p + 2) = x3;
    *(t->p + 3) = x4;
    *(t->p + 4) = x5;
    *(t->p + 5) = x6;
    *(t->p + 6) = x7;
    *(t->p + 7) = x8;
    *(t->p + 8) = x9;
}

int64_t compare_matrices(matrix a, matrix b)
{
    if (a.n != b.n || a.m != b.m)
        return FAILED;
    for (int64_t i = 0; i < a.m * a.n; i++)
    {
        if (*(a.p + i) != *(b.p + i))
        {
            return FAILED;
        }
    }
    return PASSED;
}

int64_t test_normalize_ord_col(matrix *t, matrix *tres)
{
    t->m = 3;
    resize_matrix(t, t->m * t->n);
    fill_square_matrix(tres, 1, 2, 4, 5);
    fill_2x3_matrix(t, 1, 2, 3, 4, 5, 6);
    normalize_matrix(t);
    int64_t log = compare_matrices(*t, *tres);
    t->m = 2;
    resize_matrix(t, t->m * t->n);
    return log;
}

int64_t test_normalize_ord_row(matrix *t, matrix *tres)
{
    t->n = 3;
    resize_matrix(t, t->m * t->n);
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_2x3_matrix(t, 1, 2, 3, 4, 5, 6);
    normalize_matrix(t);
    int64_t log = compare_matrices(*t, *tres);
    t->n = 2;
    resize_matrix(t, t->m * t->n);
    return log;
}

int64_t test_normalize_same(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_square_matrix(t, 1, 2, 3, 4);
    normalize_matrix(t);
    int64_t log = compare_matrices(*t, *tres);
    return log;
}

int64_t test_expo_zero(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 1, 0, 0, 1);
    fill_square_matrix(t, 1, 2, 3, 4);
    expo_matrix(t, 0);
    return compare_matrices(*t, *tres);
}

int64_t test_expo_one(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_square_matrix(t, 1, 2, 3, 4);
    expo_matrix(t, 1);
    return compare_matrices(*t, *tres);
}

int64_t test_expo_more(matrix *t, matrix *tres)
{
    fill_square_matrix(tres, 7, 10, 15, 22);
    fill_square_matrix(t, 1, 2, 3, 4);
    expo_matrix(t, 2);
    return compare_matrices(*t, *tres);
}

int64_t test_equate_same(matrix *t, matrix *tres)
{
    fill_square_matrix(t, 1, 2, 3, 4);
    fill_square_matrix(tres, 1, 2, 3, 4);
    equate_matrix(t, tres);
    return compare_matrices(*t, *tres);
}

int64_t test_equate_ord(matrix *t, matrix *tres)
{
    t->n = 3;
    resize_matrix(t, t->m * t->n);
    matrix sup;
    sup.m = 2;
    sup.n = 3;
    create_matrix(&sup);
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_2x3_matrix(t, 1, 2, 3, 4, 5, 6);
    fill_2x3_matrix(&sup, 1, 2, 3, 4, 2, 3);
    equate_matrix(t, tres);
    int64_t log = compare_matrices(sup, *tres);
    t->n = 2;
    resize_matrix(t, t->m * t->n);
    free(sup.p);
    return log;
}

int64_t test_equate_new(matrix *t, matrix *tres)
{
    t->m = 3;
    resize_matrix(t, t->m * t->n);
    matrix sup;
    sup.m = 3;
    sup.n = 3;
    create_matrix(&sup);
    fill_square_matrix(tres, 1, 2, 3, 4);
    fill_2x3_matrix(t, 1, 2, 3, 4, 5, 6);
    fill_3x3_matrix(&sup, 1, 2, 2, 3, 4, 4, 2, 3, 3);
    equate_matrix(t, tres);
    int64_t log = compare_matrices(sup, *tres);
    t->m = 2;
    resize_matrix(t, t->m * t->n);
    free(sup.p);
    return log;
}

int main()
{
    matrix t;
    matrix tres;
    int64_t c = 0;

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
    c += test_equate_same(&t, &tres);
    c += test_equate_ord(&t, &tres);
    c += test_equate_new(&t, &tres);

    printf("c = %lld out of 9", c);

    free(t.p);
    free(tres.p);

    if (c != 9)
        return ERROR;

    return OK;
}
