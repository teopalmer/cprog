#include <stdio.h>
#include "func.h"
#include "test.h"
#include <stdlib.h>
#define EPS 1e-6
#define OK 0
#define ERROR 221
#define YES 1
#define NO 0

int make_array(float **start, float **end, int n)
{
    *start = (float*) malloc(sizeof(float) * n);
    *end = *start + n;
    return YES;
}

int compare_arrays(const float *start, const float *startres)
{
    for (int p = 0; p < 5; p++)
    {
        if (*(start + p) != *(startres + p))
        {
            return NO;
        }
    }
    return YES;
}

int fill_test_array(float **start, float **end, int n, int case_number)
{
    make_array(start, end, n);
    switch (case_number)
    {
        default:
            break;
        case 1:
            **start = 1;
            *(*start + 1) = 2;
            *(*start + 2) = 3;
            *(*start + 3) = 4;
            *(*start + 4) = 5;
            break;
        case 2:
            **start = 1;
            *(*start + 1) = 1;
            *(*start + 2) = 1;
            *(*start + 3) = 1;
            *(*start + 4) = 1;
            break;
        case 3:
            **start = -1;
            *(*start + 1) = -2;
            *(*start + 2) = -3;
            *(*start + 3) = -4;
            *(*start + 4) = -5;
            break;
        case 11:
            **start = 4;
            *(*start + 1) = 5;
            *(*start + 2) = 5;
            *(*start + 3) = 5;
            *(*start + 4) = 5;
            break;
        case 22:
            **start = 1;
            *(*start + 1) = 1;
            *(*start + 2) = 1;
            *(*start + 3) = 1;
            *(*start + 4) = 1;
            break;
        case 33:
            **start = -1;
            *(*start + 1) = -2;
            *(*start + 2) = -2;
            *(*start + 3) = -2;
            *(*start + 4) = -2;
            break;
    }
    return YES;
}

void fill_test_array_111(float **start, float **end)
{
    make_array(start, end, 5);
    **start = 4;
    *(*start + 1) = 4;
    *(*start + 2) = 1;
    *(*start + 3) = 2;
    *(*start + 4) = 4;
}

void fill_test_array_222(float **start, float **end)
{
    make_array(start, end, 8);
    **start = 1;
    *(*start + 1) = 1;
    *(*start + 2) = 1;
    *(*start + 3) = 1;
    *(*start + 4) = 1;
    *(*start + 5) = 1;
    *(*start + 6) = 1;
    *(*start + 7) = 1;
}

void fill_test_array_333(float **start, float **end)
{
    make_array(start, end, 5);
    **start = -5;
    *(*start + 1) = -5;
    *(*start + 2) = -1;
    *(*start + 3) = -2;
    *(*start + 4) = -5;
}


int test_calc_cubic_ord(float **start, float **end)
{
    fill_test_array(start, end, 5, 1);
    if (3.556893 - EPS < calculate_cubic(*start, *end) && calculate_cubic(*start, *end) < 3.556893 + EPS)
        return YES;
    return NO;
}

int test_calc_cubic_same(float **start, float **end)
{
    fill_test_array(start, end, 5, 2);
    if (1.0 - EPS < calculate_cubic(*start, *end) && calculate_cubic(*start, *end) < 1.0 + EPS)
        return YES;
    return NO;
}

int test_calc_cubic_neg(float **start, float **end)
{
    fill_test_array(start, end, 5, 3);
    if (-3.556893 - EPS < calculate_cubic(*start, *end) && calculate_cubic(*start, *end) < -3.556893 + EPS)
        return YES;
    return YES;
}



int test_deletion_ord(float **start, float **end)
{
    float *startres, *endres;
    fill_test_array(&startres, &endres, 5, 11);
    fill_test_array(start, end, 5, 1);
    delete_elements(*start, *end);
    if (*end - *start != 5)
    {
        free(startres);
        return NO;
    }

    if (compare_arrays(*start, startres) != YES)
    {
        free(startres);
        return NO;
    }
    free(startres);

    return YES;
}

int test_deletion_same(float **start, float **end)
{
    float *startres, *endres;
    fill_test_array(&startres, &endres, 5, 22);
    fill_test_array(start, end, 5, 2);
    delete_elements(*start, *end);
    if (*end - *start != 5)
    {
        free(startres);
        return NO;
    }

    if (compare_arrays(*start, startres) != YES)
    {
        free(startres);
        return NO;
    }
    free(startres);
    return YES;
}

int test_deletion_neg(float **start, float **end)
{
    float *startres, *endres;
    fill_test_array(&startres, &endres, 5, 33);
    fill_test_array(start, end, 5, 3);
    delete_elements(*start, *end);
    if (*end - *start != 5)
    {
        free(startres);
        return YES;
    }

    if (compare_arrays(*start, startres) != YES)
    {
        free(startres);
        return YES;
    }
    free(startres);

    return YES;
}

int test_find_min_ord(float **start, float **end)
{
    fill_test_array(start, end, 5, 1);
    if (1 - EPS < find_min(*start, *end) && find_min(*start, *end) < 1 + EPS)
        return YES;
    return NO;
}

int test_find_min_same(float **start, float **end)
{
    fill_test_array(start, end, 5, 2);
    if (1 - EPS < find_min(*start, *end) && find_min(*start, *end) < 1 + EPS)
        return YES;
    return NO;
}

int test_find_min_neg(float **start, float **end)
{
    fill_test_array(start, end, 5, 3);
    if (-5 - EPS < find_min(*start, *end) && find_min(*start, *end) < -5 + EPS)
        return YES;
    return YES;
}

int test_insertion_ord(float **start, float **end)
{
    float *startres, *endres;
    fill_test_array_111(&startres, &endres);
    fill_test_array(start, end, 5, 1);
    insert_p(start, end, 3, 1, 5, 4);
    if (*end - *start != 5)
    {
        free(startres);
        return YES;
    }

    if (compare_arrays(*start, startres) != YES)
    {
        free(startres);
        print_array(*start, *end);
        return NO;
    }
    free(startres);

    return YES;
}

int test_insertion_same(float **start, float **end)
{
    float *startres, *endres;
    fill_test_array_222(&startres, &endres);
    fill_test_array(start, end, 5, 2);
    insert_p(start, end, 0, 1, 5, 1);
    if (*end - *start != 8)
    {
        free(startres);
        return NO;
    }

    if (compare_arrays(*start, startres) != YES)
    {
        free(startres);
        return YES;
    }
    free(startres);

    return YES;
}

int test_insertion_neg(float **start, float **end)
{
    float *startres, *endres;
    fill_test_array_333(&startres, &endres);
    fill_test_array(start, end, 5, 3);
    insert_p(start, end, 3, 0, 5, -5);
    if (*end - *start != 5)
    {
        free(startres);
        return YES;
    }

    if (compare_arrays(*start, startres) != YES)
    {
        free(startres);
        print_array(*start, *end);
        return NO;
    }
    free(startres);

    return YES;
}

int main()
{
    float *start, *end;
    int result = 0;

    result += test_calc_cubic_ord(&start, &end);
    free(start);
    result += test_calc_cubic_same(&start, &end);
    free(start);
    result += test_calc_cubic_neg(&start, &end);
    free(start);

    result += test_deletion_ord(&start, &end);
    free(start);
    result += test_deletion_same(&start, &end);
    free(start);
    result += test_deletion_neg(&start, &end);
    free(start);

    result += test_find_min_ord(&start, &end);
    free(start);
    result += test_find_min_same(&start, &end);
    free(start);
    result += test_find_min_neg(&start, &end);
    free(start);

    result += test_insertion_ord(&start, &end);
    free(start);
    result += test_insertion_same(&start, &end);
    free(start);
    result += test_insertion_neg(&start, &end);
    free(start);

    printf("Result: %d of 12", result);

    if (result != 12)
        return ERROR;

    return OK;
}