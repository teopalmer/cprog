#include <stdio.h>
#include <math.h>

int main() {
    float r1, r2, r3;
    float r;
    puts("Please enter three resistance values: ");
    scanf("%f %f %f", &r1, &r2, &r3);
    if (r1+r2+r3)
    {
        r = ((r1 * r2 * r3) / (r2*r3 + r1*r3 + r1*r2));
    }
    else
    {
        r = 0;
    }
    printf("%.5f", r);
}