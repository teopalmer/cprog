#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INPUT_ERR -1
#define LOGIC_ERR -2

#define N 10

int read_matrix(int a[N][N], int *n, int *m)
{
    int rc, matrix_el;
    int arg_count = 0;

    rc = scanf("%d%d", n, m);

    if (rc == 2)
    {
        if (*n > N || *n < 1 || *m > N || *m < 1)
        {
            printf("Input error");

            return INPUT_ERR;
        }
        else
        {
            for (int i = 0; i < *n; ++i)
            {
                for (int j = 0; j < *m; j++)
                {
                    rc = scanf("%d", &matrix_el);
                    if (rc == 1)
                    {
                        a[i][j] = matrix_el;
                        arg_count++;
                    }
                    else
                    {
                        printf("Input error");

                        return INPUT_ERR;
                    }
                }
            }

            if (arg_count != (*n) * (*m))
            {
                printf("Input error");

                return INPUT_ERR;
            }
            else
                return OK;
        }
    }
    else
    {
        printf("Input error");

        return INPUT_ERR;
    }
}

void print_matrix(int a[N][N], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            printf("%d ", a[i][j]);
    }
}

int col_deleter(int a[N][N], int n, int *m, int k)
{
    int count = 0;

    while (count < (*m))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < *m; ++j)
            {
                int curr_el = abs(a[i][j]);
                int k_count = 0;

                while (curr_el > -1)
                {
                    int d = curr_el % 10;
                    if (d == k)
                        k_count++;
                    curr_el /= 10;
                    if (curr_el == 0)
                        curr_el--;
                }
                if (k_count)
                {
                    for (int p = 0; p < n; ++p)
                        for (int q = j; q < *m; ++q)
                            a[p][q] = a[p][q + 1];
                    (*m)--;
                }
            }
        }

        count++;
    }
    if (!(*m))
    {
        printf("Empty matrix");

        return LOGIC_ERR;
    }
    else
        return OK;
}

int main()
{
    int a[N][N], n, m, k, rc;

    if (read_matrix(a, &n, &m) == INPUT_ERR)
        return INPUT_ERR;
    else
    {
        rc = scanf("%d", &k);

        if (rc != 1)
        {
            printf("Input error");

            return INPUT_ERR;
        }
        else
        {
            if (k < 0 || k > 9)
            {
                printf("Input error");

                return INPUT_ERR;
            }
            else
            {
                if (col_deleter(a, n, &m, k) == LOGIC_ERR)
                    return LOGIC_ERR;
                else
                {
                    print_matrix(a, n, m);

                    return OK;
                }
            }
        }
    }
}
