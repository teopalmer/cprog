#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERROR 221

void print_array(float *start, float *end)
{
    for (float *p = start; p < end; p++)
    {
        printf("%f ", *p);
    }
}

int read_array (float **start, float **end, int *n)
{
    puts("Enter number of elements:");

    if (scanf("%d", n) != 1) return ERROR;

    *start = (float*)malloc(sizeof(float)*(*n));
    if (!(*start)) return ERROR;
    *end = *start + *n;

    puts("Enter elements:");
    for (float *p = *start; p < *end; p++)
    {
        if (scanf("%f", p) != 1) return ERROR;
    }

    if (*start == *end) return ERROR;
    return OK;
}

int read_p(int *p)
{
    puts("Enter p:");
    if (scanf("%d", p) != 1)
    {
	puts("Input Error");
        return ERROR;
    }
    if (*p <= 0)
    {
	puts("Negative P");
        return ERROR;
    }
    return OK;
}

int insert_p(float **start, float **end, int n, int p, int count)
{
    if (count < p + 2) return ERROR;
    if (count <= 0) return ERROR;
    int difference = count - n + 3;
    //printf("%d %d %d\n", difference, count, n);

    float* newstart = (float*) realloc(*start, sizeof(newstart) * (difference));

    if (newstart)
    {
        *start = newstart;
        *end = *start + difference;
        newstart = NULL;
    }
    else
    {
        return ERROR;
    }

    float *pos = *start + p;

    for (float *c = *end; c > *start; c--)
    {
        *c = *(c - 1);
    }
    **start = (float)p;

    for (float *c = *end; c > pos; c--)
    {
        *c = *(c - 1);
    }

    *(*start + p) = p;
    *(*end - 1) = (float)p;
    
    return OK;
}

double calculate_cubic(float *start, float *end)
{
    double sum = 0;
    int n = 0;
    for (float *p = start; p < end; p++)
    {
        sum += fabs(*p * *p * *p);
        n++;
    }
    return cbrt(sum/n);
}

int delete_elements(float *start, float *end, double cubic)
{
    int n = 0;
    //printf("end = %f", *(end-1));
    //puts("*");
    //printf("%f", *end);
    for (float *p = start; p < end - n; p++)
    {
        if (fabs(*p) < cubic)
        {
            for (float *c = p+1; c < end - n; c++)
            {
                *(c - 1) = *c;
            }
	    //if (p >= end - n) p++;
            p--;
            n++;
        }
    }
    //if (n == 0) return ERROR;
    return n;
}

