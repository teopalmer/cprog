#include <stdio.h>
#include <math.h>

int main()
{
    float x, eps, sum = 0;
    double ab, otn;
    double c = 1, f;
    int n = 2, ch;
    ch = scanf("%f %f", &x, &eps);
    if (ch != 2)
    {
        puts("Input Error");
        return 11;
    }
    if (fabs(x) >= 1)
    {
        puts("Input Error");
        return 22;
    }
    else
    {
        f = pow((1 + x), -3);
        if (1 > eps)
        {
            sum = 1;
        }
        while (fabs(c) > eps)
        {
            c = pow(-1, (n + 1)) * ((pow(x, (n - 1)) * n * (n + 1)) / 2);
            //printf("* %f ", c);
            sum += c;
            n++;
        }
        ab = fabs(f - sum);
        otn = fabs(ab / f);
        printf("%.6lf, %.6lf %.6lf %.6lf", sum, f, ab, otn);
        return 0;
    }
}
