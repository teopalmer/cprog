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
    float minx = 0;
    if (read_array(&start, &end, &count) != OK)
    {
	puts("Input Error");
        return ERROR;
    }
    minx = find_min(start, end);
    del_count = delete_elements(start, end);
    if (read_p(&p) != OK)
    {
	puts("P Error");
	free(start);
        return ERROR;
    }
    minx = find_min(start, end - del_count);
    if (insert_p(&start, &end, del_count, p, count, minx) != OK)
    {
	puts("Input P Error");
	free(start);
        return ERROR;
    }
    print_array(start, end);
    free(start);
    return 0;
    
}