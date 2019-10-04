#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERROR 221
#define FAILED 0
#define PASSED 1
#define CUR_ELEMENT *((a_m.p) + j + i * (a_m.m))
#define MAT_END (a_m->p + a_m->n * a_m->m)
#define AM a_m.m - 1
#define AN a_m.n - 1

#ifndef LAB_09_FUNC_H

typedef struct
{
    int m;
    int n;
    int *p;
} matrix;

int find_max(matrix a_m, int *maxn, int *maxm);
int calc_mean_column(matrix a_m, int col);
int find_max_row(matrix a_m, int row);
int multiply_matrix(matrix a_m, matrix b_m, matrix *M);
int expo_matrix(matrix *a_m, int power);
int copy_matrix(matrix O, matrix *N);

#define LAB_09_FUNC_H

#endif //LAB_09_FUNC_H
