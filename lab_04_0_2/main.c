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
    int ch;
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
        return 100;
    }
    for (int i = 0; i < n; i++)
    {
        if (x[i] > ar)
        {
            printf("%d ", x[i]);
        }
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
    
    if (array(n) == 100 || array(n) == 0)
    {
        printf("Input Error");
        return 4;
    }
    else
    {
        array(n);
    }
}
