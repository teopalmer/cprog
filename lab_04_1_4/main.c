#include <stdio.h>
#define N 100

int input(int *x, int *n)
{
    int ch;
    ch = scanf("%d", n);
    if ((ch != 1) || (*n <= 0) || (*n > 10))
    {
        return -1;
    }
    else
        for (int i = 0; i < *n; i++)
        {
            ch = scanf("%d", &x[i]);
            if (ch != 1)
            {
                return -1;
            }
        }
    return 0;
}

void insertionsort(int n, int *a)
{
    int new, l;
    
    for (int i = 1; i < n; i++)
    {
        new = a[i];
        l = i - 1;
        while (l >= 0 && a[l] > new)
        {
            a[l + 1] = a[l];
            l = l - 1;
        }
        a[l + 1] = new;
    }
}

int main()
{
    int x[N];
    int n = 0;
    int p = input(x, &n);
    
    if (p == -1)
    {
        printf("Input Error");
        return 4;
    }
    
    insertionsort(n, x);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    return 0;
}
