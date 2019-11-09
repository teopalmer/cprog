#include "defines.h"
#include "user_interface.h"
#include "resize_matrix.h"

int main() {
    matrix_t a;
    matrix_t b;

    if (scan_size(&a) != ok)
        return input_error;

    if (create_matrix(&a, a.m * a.m) != ok)
        return memory_error;
    if (create_new_matrix(&b, a.m) != ok)
    {
        clean(&a);
        return memory_error;
    }

    if (scan_matrix(&a) != ok)
    {
        clean(&a);
        clean(&b);
        return memory_error;
    }

    fill_newmatrix(&b, a);
    print_new_matrix(b);
    clean(&a);
    clean(&b);

    return 0;
}