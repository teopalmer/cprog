#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OK 0
#define EPS 1e-6
#define ERROR 221

void print_array(float *start, float *end)
{
    for (float *p = start; p < end; p++)
    {
        printf("%f ", *p);
    }
}

int read_array(float **start, float **end, int *n)
{
    puts("Enter number of elements:");

    if (scanf("%d", n) != 1) 
        return ERROR;
    if (n <= 0)
        return ERROR;

    *start = (float*) malloc(sizeof(float)*(*n));
    if (!(*start)) 
    {
        free(start);
        return ERROR;
    }
        //return ERROR;
    *end = *start + *n;

    puts("Enter elements:");
    for (float *p = *start; p < *end; p++)
    {
        if (scanf("%f", p) != 1)
        {
            free(*start);
            return ERROR;
        }
    }

    if (*start == *end)
    {
        free(*start);
        return ERROR;
    }
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
    if (*p < 0)
    {
        puts("Negative P");
        return ERROR;
    }
    return OK;
}

int insert_p(float **start, float **end, int n, int p, int count, float cubic)
{
    if (count + 2 < p)
        return ERROR;
    if (count <= 0)
        return ERROR;
    int difference = count - n + 3;

    float *newstart = (float*)realloc(*start, sizeof(newstart) * (difference));

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
    **start = cubic;

    for (float *c = *end; c > pos; c--)
    {
        *c = *(c - 1);
    }

    *(*start + p) = cubic;
    *(*end - 1) = cubic;

    return OK;
}

float find_min(float *start, float *end)
{
    float minx = *start;
    for (float *p = start; p < end; p++)
    {
        if (*p < minx)
            minx = *p;
    }
    return minx;
}

float calculate_cubic(float *start, float *end)
{
    float sum = 0;
    int n = 0;
    for (float *p = start; p < end; p++)
    {
        sum += fabsf(*p * *p * *p);
        n++;
    }
    return cbrtf(sum / n);
}

int delete_elements(float *start, float *end)
{
    int n = 0;
    float cubic = calculate_cubic(start, end);
    for (float *p = start; p < end - n; p++)
    {
        if ((fabsf(*p) + EPS) < cubic)
        {
            for (float *c = p + 1; c < end - n; c++)
            {
                *(c - 1) = *c;
            }
            //if (p >= end - n) p++;
            p--;
            n++;
        }
    }
    return n;
}
