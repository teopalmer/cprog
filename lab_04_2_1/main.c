#include <stdio.h>
#define N 10

int input()
{
    int n, ch;
    ch = scanf("%d", &n);
    if ((ch != 1) || (n <= 0))
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
        ar = 0;
    }
    return ar;
}

void output(float ar)
{
    printf("%.6f", ar);
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
    output(out);
    return 0;
}
