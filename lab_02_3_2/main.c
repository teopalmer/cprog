#include <stdio.h>
#include <math.h>

int main()
{
    int ch;
    float x1, y1, x2, y2;
    float xa, ya, k = 1;
    int res = 1;
    ch = scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &xa, &ya);
    if (ch != 6)
    {
        printf("Input error");
        return 11;
    }
    else
    {
        k = (x1 - xa) * (y2 - y1) - (x2 - x1) * (y1 - ya);
        if (k > 0)res = 0;
        if (k < 0)res = 2;
        printf("%d", res);
        return 0;
    }
}
