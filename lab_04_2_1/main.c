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
    int c = 0;
    float sum = 0;
    float ar = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (x[i] < 0)
        {
            sum += x[i];
            c++;
        }
    }
    if (c > 0)
    {
        ar = sum / c;
    }
    else
    {
        return 100;
    }
    return ar;
}

void output(float ar)
{
    printf("%.6f", ar);
}

int main()
{
    int x[N];
    int n = 0;
    int p = input(x, &n);
    
    if (p == -1 || array(x, n) == 100)
    {
        printf("Input Error");
        return 4;
    }
    
    output(array(x, n));
    return 0;
}
