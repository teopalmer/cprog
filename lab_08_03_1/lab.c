#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#define OK 0
#define ERROR 221

int main()
{
    int p;
    float *end;
    float *start;
    int del_count = 0;
    int count = 0;
    if (read_array(&start, &end, &count) != OK)
    {
	puts("Input Error");
	free(start);
        return ERROR;
    }
    //print_array(start, end);
    //printf("%d", count);
    del_count = delete_elements(start, end, calculate_cubic(start, end));
    //print_array(start, end);
    if (read_p(&p) != OK)
    {
	puts("P Error");
        return ERROR;
    }
    if (insert_p(&start, &end, del_count, p, count) != OK)
    {
	puts("Input P Error");
	//free(start);
        return ERROR;
    }
    print_array(start, end);
    //printf("%lf", calculate_cubic(start, end));
    free(start);
    return 0;
    
}