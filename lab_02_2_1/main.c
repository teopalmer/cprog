#include <stdio.h>
#include <math.h>

int main()
{
    int ch;
    int n, f0 = 0, f1 = 1, c = 2;
    int x;
    ch = scanf("%d", &n);
    if (ch != 1)
    {
        puts("Input error");
        return 11;
    }
    if ((n < 0) || (n > 50))
    {
        puts("Input error");
        return 22;
    }
    else
    {
        if (n == 0)
        {
            printf("0");
        }
        else if (n == 1)
        {
            printf("1");
        }
        else
        {
            while (c <= n)
            {
                c++;
                x = (f0 + f1);
                f0 = f1;
                f1 = x;
            }
            printf("%d", x);
        }
        return 0;
    }
}
