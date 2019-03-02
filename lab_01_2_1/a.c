#include <stdio.h>
#include <math.h>

int main()
{
    double x1, x2, x3, y1, y2, y3;
    double p;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    p = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    p += sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    p += sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    printf("%.5f", p);
}
