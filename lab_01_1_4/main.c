#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int f, p;
    
    scanf("%d", &n);
    
    n -= 1;
    p = n / 36;
    f = (n % 36) / 4;
    printf("%d %d", p + 1, f + 1);
    
    return 0;
}
