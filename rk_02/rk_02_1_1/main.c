#include <stdio.h>
#include <string.h>
#define N 101
#define OK 0
#define ERROR 4
typedef int matr_t[N][N];

int input(int *n, matr_t A)
{
    int ch = 0;
    ch = scanf("%d", n);
    if (ch != 1 || n <= 0)
        return ERROR;
    //(*n)++;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            ch = scanf("%d", &A[i][j]);
            if (ch != 1)
                return ERROR;
        }
    }
    return OK;
}

void switch_diagonal(int n, matr_t A)
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                tmp = A[i][j];
                A[i][j] = A[i][n - 1 - j];
                A[i][n - 1 - j] = tmp;
            }
        }
    }
    
}

void output(int n, const matr_t A)
{
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        puts("");
    }
}

int main()
{
    int n = 0;
    matr_t A;
    input(&n, A);
    switch_diagonal(n, A);
    output(n, A);
    return 0;
}
