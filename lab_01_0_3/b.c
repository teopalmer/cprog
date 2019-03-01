#include <stdio.h>
#include <math.h>

int main()
{
    float h, t, m;
    float norm_m, index_m;
    
    scanf("%f %f %f", &h, &t, &m);
    
    norm_m = (h * t) / 240;
    
    h = h / 100;
    index_m = m / (h * h);
    
    printf("%.5f %.5f", norm_m, index_m);
    return 0;
}
