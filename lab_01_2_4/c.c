/* Программа вычисляет площадь трапеции,
исходя из величины ее оснований и угла */
#include <stdio.h>
#include <math.h>

int main() {
    int s;
    int m;
    puts("Please enter seconds: ");
    scanf("%d", &s);
    m = s/60;
    s %= 60;
    printf("%d %d", m, s);
}
