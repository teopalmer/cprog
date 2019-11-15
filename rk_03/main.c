#include "defines.h"
#include "user_interface.h"
#include "resize_matrix.h"

int main() {
    matrix_t a;
    matrix_t new;

    scan_matrixsize(&a);
    create_matrix(&a);

    new.m = a.m;
    new.n = a.n;

    reshape_matrix(&new, a);
    create_new_matrix(&new);
    scan_matrix(&a);
    print_matrix(a);
    fill_newmatrix(&new, a);
    print_newmatrix(new);

    for (int i = 0; i < a.m; i++)
    {
        free(a.p[i]);
    }
    free(a.p);

    return 0;
}