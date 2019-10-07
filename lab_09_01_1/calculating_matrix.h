#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

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
    int64_t m;
    int64_t n;
    int64_t *p;
} matrix;

int64_t find_max(matrix a_m, int64_t *maxn, int64_t *maxm);
int64_t calc_mean_column(matrix a_m, int64_t col);
int64_t find_max_row(matrix a_m, int64_t row);
int64_t multiply_matrix(matrix a_m, matrix b_m, matrix *m_m);
int64_t expo_matrix(matrix *a_m, int64_t power);
int64_t copy_matrix(matrix old, matrix *newm);

#define LAB_09_FUNC_H

#endif //LAB_09_FUNC_H
