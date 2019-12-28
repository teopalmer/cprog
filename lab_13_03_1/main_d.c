#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

#include "func.h"

int main()
{
    void *handle;
    char *error;
    
    void (*print_array)(float *start, float *end);
    int (*read_array)(float **start, float **end, int *n);
    int (*read_p)(int *p);
    int (*insert_p)(float **start, float **end, int n, int p, int count, float cubic);
    float (*find_min)(float *start, float *end);
    float (*calculate_cubic)(float *start, float *end);
    int (*delete_elements)(float *start, float *end);
    
    int p;
    float *end;
    float *start;
    int del_count = 0;
    int count = 0;
    float minx = 0;
    handle = dlopen("darray.so", RTLD_LAZY);
    
    if (!handle) {
        return 1;
    }
    
    dlerror();
    print_array = (void (*)(float *, float *)) dlsym(handle, "print_array");
    read_array = (int (*)(float **, float **, int *)) dlsym(handle, "read_array");
    read_p = (int (*)(int *)) dlsym(handle, "read_p");
    insert_p = (int (*)(float **start, float **end, int n, int p, int count, float cubic)) dlsym(handle, "insert_p");
    find_min = (float (*)(float *start, float *end)) dlsym(handle, "find_min");
    delete_elements = (int (*)(float *start, float *end)) dlsym(handle, "delete_elements");
    error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    
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
