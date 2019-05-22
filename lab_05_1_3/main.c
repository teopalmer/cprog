#include <stdio.h>
#define N 10
#define VALUE_ERROR 4
#define OK 0

int input(int x[N][N], int *n, int *m)
{
    int ch;
    ch = scanf("%d", n);
    if (ch != 1 || *n <= 0 || *n > 10)
    {
        puts("Incorrect row number");
        return VALUE_ERROR;
    }
    
    ch = scanf("%d", m);
    if (ch != 1 || *m <= 0 || *m > 10)
    {
        puts("Incorrect column number");
        return VALUE_ERROR;
    }
    
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            ch = scanf("%d", &x[i][j]);
            if (ch != 1)
            {
                puts("Incorrect symbol");
                return VALUE_ERROR;
            }
        }
    }
    return 0;
}

int max_find(int x[N][N], int k, int m)
{
    int min = x[k][0];
    for (int j = 0; j < m; j++)
    {
        if (x[k][j] > min)
            min = x[k][j];
    }
    return min;
}

void switcher(int x[N][N], int m, int i, int k)
{
    int t;
    for (int j = 0; j < m; j++)
    {
        t = x[i][j];
        x[i][j] = x[k][j];
        x[k][j] = t;
    }
}

void sort_m(int x[N][N], int n, int m)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (max_find(x, j, m) > max_find(x, j - 1, m))
                switcher(x, m, j, j - 1);
        }
    }
}

void output(int x[N][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", x[i][j]);
        }
    }
}

int main()
{
    int x[N][N];
    int n, m;
    if (!input(x, &n, &m))
    {
        sort_m(x, n, m);
        output(x, n, m);
        return OK;
    }
    else
        return VALUE_ERROR;
}

