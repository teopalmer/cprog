#include "calculating_matrix.h"

#ifndef LAB_09_RESIZING_MATRIX_H

void delete_column(matrix *a_m, int col);
void delete_row(matrix *a_m, int row);
int normalize_matrix(matrix *a_m);
int create_matrix(matrix *a_m);
void add_column(matrix *a_m);
void add_row(matrix *a_m);
void equate_matrix(matrix *a_m, matrix *b_m);

#define LAB_09_RESIZING_MATRIX_H

#endif //LAB_09_RESIZING_MATRIX_H
