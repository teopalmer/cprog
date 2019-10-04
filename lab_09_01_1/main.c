#include <stdio.h>
#include <stdlib.h>
#include "calculating_matrix.h"
#include "resizing_matrix.h"
#include "user_interface.h"

int main() {
    matrix a_m;
    matrix b_m;
    matrix M;
    int pheta = 0;
    int gamma = 0;

    if (read_matrix(&a_m) != OK)
        return ERROR;
    if (read_matrix(&b_m) != OK)
        return ERROR;

    normalize_matrix(&a_m);
    normalize_matrix(&b_m);
    equate_matrix(&a_m, &b_m);

    M.m = a_m.m;
    M.n = a_m.n;
    create_matrix(&M);

    read_exp(&pheta, &gamma);
    expo_matrix(&a_m, pheta);
    expo_matrix(&b_m, gamma);

    multiply_matrix(a_m, b_m, &M);
    print_matrix(M);

    free(a_m.p);
    free(b_m.p);
    free(M.p);
    return 0;
}
