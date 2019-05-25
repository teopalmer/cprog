#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 101
#define OK 0
#define ERROR 4
typedef struct
{
    char name[N];
    int year;
    int population;
} Town;

int input(FILE *f, Town *t)
{
    int a = fscanf(f, "%[^\n]s", t->name);
    int b = fscanf(f, "%d", &t->year);
    int c = fscanf(f, "%d", &t->population);
    fgetc(f);
    if (a != 1 || b != 1 || c!= 1)
    {
        puts("*");
        return ERROR;
    }
    
    return OK;
}

/*void input_struct(FILE *f, Town *t)
 {
 int maxlen = 0;
 int x = input(f, t);
 
 while (!x)
 {
 printf("%s %d %d\n", t->name, t->year, t->population);
 if (strlen(t.name) > maxlen)
 {
 maxlen = strlen(t->name);
 indi = i;
 }
 sum += t->population;
 printf("sum: %d\n", sum);
 i++;
 x = input(stdin, t);
 }
 }*/


float get_avg(int n, float sum)
{
    if (n != 0)
        return sum/n;
    else
        return -1;
}

void output(FILE *f, int one, float all)
{
    float k = abs(all-one);
    fprintf(f, "%f", k);
    //printf("%f", k);
}

int main()
{
    Town T[N];
    int i = 0;
    int indi = 0;
    int sum = 0;
    FILE *f_in;
    FILE *f_out;
    int maxlen = 0;
    
    f_in = fopen("in.txt", "rt");
    f_out = fopen("out.txt", "a");
    int x = input(f_in, &T[i]);
    
    while (!x)
    {
        printf("%s %d %d\n", T[i].name, T[i].year, T[i].population);
        if (strlen(T[i].name) > maxlen)
        {
            maxlen = strlen(T[i].name);
            indi = i;
        }
        sum += T[i].population;
        printf("sum: %d\n", sum);
        i++;
        x = input(f_in, &T[i]);
    }
    
    float g = get_avg(i, sum);
    printf("g: %f\n", g);
    printf("indi: %d\n", indi);
    //printf("p[i]: %d\n", T[indi].population);
    
    if (g < 0)
        return ERROR;
    else
        output(f_out, T[indi].population, g);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
