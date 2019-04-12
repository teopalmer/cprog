#include <stdio.h>
#define N 10
#define VALUE_ERROR 4
#define OK 0

int input(int *n, int *m, int *k)
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
    ch = scanf("%d", k);
    if (ch != 1 || *k > (*n * *m))
    {
        puts("Incorrect number");
        return VALUE_ERROR;
    }
    return OK;
}

int input_array(int x[N * N], int n, int m)
{
    int ch;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int num = i * m + j;
            ch = scanf("%d", &x[num]);
            if (ch != 1)
            {
                puts("Incorrect symbol");
                return VALUE_ERROR;
            }
        }
    return OK;
}

int is_ord(int x[N * N], int n, int m, int k)
{
    int num = k % m;
    for (int j = num; j < m; j += num)
    {
        if (x[j + num] - x[j] > 0)
            return VALUE_ERROR;
    }
    return OK;
}

int main()
{
    int x[N * N];
    int n, m, k;
    if (!input(&n, &m, &k) && !input_array(x, n, m))
    {
        x[k] = is_ord(x, n, m, k);
        for (int i = 0; i < n * m; i++)
            printf("%d ", x[i]);
    }
    else
        return VALUE_ERROR;
}
