#include <stdio.h>
#include <math.h>

int main()
{
    int s;
    int c, m;
    puts("Please enter seconds: ");
    scanf("%d", &s);
    c = s / 3600;
    m = (s % 3600) / 60;
    s %= 60;
    printf("%d %d %d", c, m, s);
}
