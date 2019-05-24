#include <stdio.h>
#define OK 0
#define WRONG_ARG 2
#define EMPTY_FILE 3
#define FILE_ERROR 4
#define EXECUTION_ERROR 5

int find_max(FILE *f, int *max)
{
    int cur_m = -1;
    int xprev = 0, xnow = 0;
    int xnext = 0;
    
    if (!f)
    {
        puts("file is nowhere to be found");
        return FILE_ERROR;
    }
    
    if (feof(f))
    {
        puts("the file is empty tho..");
        return EMPTY_FILE;
    }
    
    if (fscanf(f, "%d %d", &xprev, &xnow) == 2)
    {
        if (xprev < 0 && xnow >= 0)
            cur_m = xnow;
        
        while (!feof(f))
        {
            if (fscanf(f, "%d", &xnext) == 1)
            {
                if (xnow < 0 && xnext >= 0 && xnext > cur_m)
                    cur_m = xnext;
                xprev = xnow;
                xnow = xnext;
            }
            else
            {
                puts("that wont do hon");
                return WRONG_ARG;
            }
        }
        *max = cur_m;
        if (cur_m < 0)
            return WRONG_ARG;
        return OK;
    }
    puts("smth dead wrong mate");
    return WRONG_ARG;
}

int main()
{
    int max_count = -1;
    if (!find_max(stdin, &max_count) && max_count != -1)
    {
        printf("%d", max_count);
        return OK;
    }
    return EXECUTION_ERROR;
}
