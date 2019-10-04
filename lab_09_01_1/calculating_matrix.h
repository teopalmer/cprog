#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERROR 221
#define CUR_ELEMENT *((A.p) + j + i * (A.m))
#define MAT_END (A->p + A->n * A->m)
#define AM A.m - 1
#define AN A.n - 1

#ifndef LAB_09_FUNC_H

typedef struct
{
    int m;
    int n;
    int *p;
} matrix;

int find_max(matrix A, int *maxn, int *maxm);
int calc_mean_column(matrix A, int col);
int find_max_row(matrix A, int row);
int multiply_matrix(matrix A, matrix B, matrix *M);
int expo_matrix(matrix *A, int power);
int copy_matrix(matrix O, matrix *N);

#define LAB_09_FUNC_H

#endif //LAB_09_FUNC_H
