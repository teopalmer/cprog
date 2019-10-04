#include <stdio.h>
#include <stdlib.h>
#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int main() {
    matrix A;
    matrix B;
    matrix M;
    int pheta = 0;
    int gamma = 0;

    if (read_matrix(&A) != OK)
        return ERROR;
    if (read_matrix(&B) != OK)
        return ERROR;

    normalize_matrix(&A);
    normalize_matrix(&B);
    equate_matrix(&A, &B);

    M.m = A.m;
    M.n = A.n;
    create_matrix(&M);

    read_exp(&pheta, &gamma);
    expo_matrix(&A, pheta);
    expo_matrix(&B, gamma);

    multiply_matrix(A, B, &M);
    print_matrix(M);

    free(A.p);
    free(B.p);
    free(M.p);
    return 0;
}