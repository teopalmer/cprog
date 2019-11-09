//
// Created by Teo on 2019-11-02.
//

#ifndef RK_03_RESIZE_MATRIX_H
int create_matrix(matrix_t *a, int size);
int delete_row(matrix_t *a, int row);
int create_new_matrix(matrix_t *a, int size);
int fill_newmatrix(matrix_t *new, matrix_t old);
int clean(matrix_t *a);
#define RK_03_RESIZE_MATRIX_H

#endif //RK_03_RESIZE_MATRIX_H
