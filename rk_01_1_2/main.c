#include <stdio.h>
#define N 100

int numbers_output(int *n, int a[N], int *k)
{
    int c;
    c = scanf("%d", n);
    if (c != 1 || *n <= 0 || *n > 100)
        return -1;
    for (int i = 0; i < *n; i++)
    {
        c = scanf("%d", &a[i]);
        if (c != 1)
            return -1;
    }
    c = scanf("%d", k);
    if (c != 1)
        return -1;
    return 0;
}

int array(int a[N], int k, int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] % k == 0) && (count == 0))
        {
            count = 1;
            for (int j = i; j < n; j++)
                a[j] = a[j + 1];
            n--;
        }
        else if ((a[i] % k == 0) && (count == 1))
        {
            count--;
        }
    }
    return n;
}

void output(int a[N], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int p;
    int n, k;
    int a[N];
    if (numbers_output(&n, a, &k) == -1)
    {
        return 4;
    }
    p = array(a, k, n);
    output(a, p);
    return 0;
}
