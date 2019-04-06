#include <stdio.h>
#include <stdlib.h>

int output()
{
    int c;
    int n = 0;
    c = scanf("%d", &n);
    if (c != 1)
    {
        return -4;
    }
    return abs(n);
}

int maxfind(int n)
{
    int ch = 0;
    int m = n % 10;
    while (n != 0)
    {
        ch = n % 10;
        n /= 10;
        if (ch >= m)
            m = ch;
    }
    return m;
}

int minfind(int n)
{
    int ch = 0;
    int m = n % 10;
    while (n != 0)
    {
        ch = n % 10;
        n /= 10;
        if (ch <= m)
            m = ch;
    }
    return m;
}

int main()
{
    int n = output();
    if (n == -4)
        return 4;
    printf("%d ", maxfind(n));
    printf("%d", minfind(n));
    return 0;
}

