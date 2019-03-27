#include <stdio.h>
#define N 100

int input()
{
    int n, ch;
    ch = scanf("%d", &n);
    if ((ch != 1) || (n <= 0) || (n >= 10))
    {
        return -1;
    }
    else
        return n;
}

float array(int n)
{
    int x[N];
    int ch, c = 0;
    float sum = 0;
    float ar = 0;
    
    for (int i = 0; i < n; i++)
    {
        ch = scanf("%d", &x[i]);
        if (ch != 1)
        {
            return 100;
        }
        else
        {
            sum += x[i];
        }
    }
    if (n > 0)
    {
        ar = sum / n;
    }
    else
    {
        ar = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (x[i] > ar)
        {
            printf("%d ", x[i]);
        }
    }
}

int main()
{
    int n = input();
    if (n == -1)
    {
        printf("Input Error");
        return 4;
    }
    
    array(n);
}

