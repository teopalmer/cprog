#include <stdio.h>
#include <math.h>

int main()
{
    int ch;
    float x1, y1, x2, y2;
    float xA, yA, k = 1;
    int res = 1;
    ch = scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &xA, &yA);
    if (ch != 6)
    {
        printf("Input error");
        return 11;
    }
    else
    {
        k = (x1 - xA) * (y2 - y1) - (x2 - x1) * (y1 - yA);
        if (k > 0) res = 0;
        if (k < 0) res = 2;
        printf("%d", res);
        return 0;
    }
    
}
