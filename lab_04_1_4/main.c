#include <stdio.h>
#define N 100

int input()
{
    int n, ch;
    ch = scanf("%d", &n);
    if ((ch != 1) || (n <= 0) || (n > 10))
    {
        return -1;
    }
    else
        return n;
}

void insertionsort(int n, int a[])
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

float array(int n)
{
    int x[N];
    int ch;
    
    for (int i = 0; i < n; i++)
    {
        ch = scanf("%d", &x[i]);
        if (ch != 1)
        {
            return 100;
        }
    }
    insertionsort(n, x);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    return 0;
}

int main()
{
    int n = input();
    if (n == -1)
    {
        printf("Input Error");
        return 4;
    }
    
    if (array(n) == 100)
    {
        printf("Input Error");
        return 4;
    }
    
    return 0;
}
