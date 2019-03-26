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

int reverse(int n)
{
    int r1 = 0, r2 = 0;
    while (n > 0)
    {
        r1 = n % 10;
        r2 = r2 * 10 + r1;
        n /= 10;
    }
    return r2;
}

int array(int n)
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
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0)
        {
            n++;
            for (int j = n - 1; j > i; j--)
            {
                x[j] = x[j - 1];
            }
            x[i + 1] = reverse(x[i]);
            i++;
        }
    }
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
    
    float out = array(n);
    if (out == 100)
    {
        printf("Input Error");
        return 4;
    }
    return 0;
}

