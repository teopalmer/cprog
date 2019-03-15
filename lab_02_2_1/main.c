#include <stdio.h>
#include <math.h>

int main()
{
    int ch;
    int n, f0 = 0, f1 = 1, c = 2;
    int x;
    puts("Please enter n: ");
    ch = scanf("%d", &n);
    if ((ch != 1) || (n < 0))
    {
        puts("Input error");
        return 11;
    }
    else
    {
        if (n == 1)
        {
            printf("0");
            
        }
        if (n >= 2) printf("0 1 ");
        while (c < n)
        {
            c++;
            x = (f0 + f1);
            printf("%d ", x);
            f0 = f1;
            f1 = x;
        }
        return 0;
    }
}
