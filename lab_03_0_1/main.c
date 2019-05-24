#include <stdio.h>
#define OK 0
#define WRONG_ARG -1
#define EMPTY_FILE -2
#define FILE_ERROR -3
#define EXECUTION_ERROR -4

int find_maximum(FILE *f, int *max)
{
    int cur_m = -1;
    int xprev = 0, xnow = 0;
    int xnext = 0;
    
    if (!f)
        return FILE_ERROR;
    
    if (feof(f))
        return EMPTY_FILE;
    
    if (fscanf(f, "%d%d", &xprev, &xnow) == 2)
    {
        if (xprev < 0 && xnow > 0)
            cur_m = xnow;
        
        while (!feof(f))
        {
            if (fscanf(f, "%d", &xnext) == 1)
            {
                if (xnow < 0 && xnext > 0 && xnext > cur_m)
                    cur_m = xnow;
                xprev = xnow;
                xnow = xnext;
            }
            else
                return WRONG_ARG;
        }
        
        *max = cur_m;
        
        return OK;
    }
    
    return WRONG_ARG;
}

int main()
{
    int max_count = 0;
    if (find_maximum(stdin, &max_count) == OK)
    {
        printf("%d", max_count);
        
        return OK;
    }
    
    return EXECUTION_ERROR;
}
