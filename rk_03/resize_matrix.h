//
// Created by Teo on 2019-11-02.
//

#ifndef RK_03_RESIZE_MATRIX_H
int create_matrix(matrix_t *a);
int delete_row(matrix_t *a, int row);
int reshape_matrix(matrix_t *a, matrix_t old);
int create_new_matrix(matrix_t *a);
int fill_newmatrix(matrix_t *a, matrix_t old);
int delete_row(matrix_t *a, int row);
#define RK_03_RESIZE_MATRIX_H

#endif //RK_03_RESIZE_MATRIX_H
