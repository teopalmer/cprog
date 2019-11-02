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

    /*p = calloc((size_t)m, sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        p[i] = calloc((size_t)n, sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    //puts("");
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", p[i][j]);
        }
        puts("");
    }

    int nk = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (p[nk][j - 1] > p[nk][j])
            {
                int temp = p[nk][j];
                p[nk][j] = p[nk][j - 1];
                p[nk][j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", p[i][j]);
        }
        puts("");
    }*/

    return 0;
}