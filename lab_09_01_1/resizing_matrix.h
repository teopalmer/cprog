#include "calculating_matrix.h"

#ifndef LAB_09_RESIZING_MATRIX_H

void delete_column(matrix *A, int col);
void delete_row(matrix *A, int row);
int normalize_matrix(matrix *A);
int create_matrix(matrix *A);
void add_column(matrix *A);
void add_row(matrix *A);
void equate_matrix(matrix *A, matrix *B);

#define LAB_09_RESIZING_MATRIX_H

#endif //LAB_09_RESIZING_MATRIX_H
