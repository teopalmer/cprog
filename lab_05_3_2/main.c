#include <stdio.h>
#define N 10
#define VALUE_ERROR 4
#define OK 0

int input(int x[N][N], int *n, int *m, int *k)
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
        for (int j = 0; j < *m; j++)
        {
            ch = scanf("%d", &x[i][j]);
            if (ch != 1)
            {
                puts("Incorrect symbol");
                return VALUE_ERROR;
            }
        }
    
    ch = scanf("%d", k);
    if (ch != 1)
    {
        puts("Incorrect number");
        return VALUE_ERROR;
    }
    return OK;
}

int col_remover(int x[N][N], int n, int *m, int k)
{
    int fm = *m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < *m; j++)
        {
            if (x[i][j] == k)
            {
                for (int l = 0; l < n; l++)
                for (int p = j; p < *m; p++)
                {
                    x[l][p] = x[l][p+1];
                }
                (*m)--;
            }
        }
    
    if (fm == *m || *m == 0)
        return VALUE_ERROR;
    return OK;
}

void output(int x[N][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", x[i][j]);
        puts("");
    }
}

int main()
{
    int x[N][N];
    int n, m, k;
    if (!input(x, &n, &m, &k) && !col_remover(x, n, &m, k))
    {
        output(x, n, m);
    }
    else
    return VALUE_ERROR;
}
