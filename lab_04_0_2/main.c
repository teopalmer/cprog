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

float array(int *x, int n)
{
    int f = 0;
    float sum = 0;
    float ar = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum += x[i];
    }
    
    ar = sum / n;
    
    for (int i = 0; i < n; i++)
    {
        if (x[i] > ar)
        {
            f = 1;
            printf("%d ", x[i]);
        }
    }
    if (f == 0)
    {
        return -1;
    }
    return 0;
}

int main()
{
    int n, x[N];
    if (!(input(x, &n)) && !(array(x, n)))
        return 0;
    else
    {
        puts("Input Error");
        return -1;
    }
}
