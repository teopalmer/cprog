#include <stdio.h>
#define N 100
#define OK 0
#define WRONG_ARG 2
#define EMPTY_FILE 3
#define FILE_ERROR 4

int search(FILE *f, float avg, int *c)
{
    float t;
    rewind(f);
    while (fscanf(f, "%f", &t) == 1)
    {
        if (t > avg)
            (*c)++;
    }
    if (c == 0)
    {
        puts("No numbers here");
        return WRONG_ARG;
    }
    return OK;
}

int min_max(FILE *f, float *min_num, float *max_num)
{
    float t;
    int flag = 0;
    if (fscanf(f, "%f", min_num) == 1)
    {
        *max_num = *min_num;
        while (fscanf(f, "%f", &t) == 1)
        {
            flag = 1;
            
            if (t > *max_num)
                *max_num = t;
            
            if (t < *min_num)
                *min_num = t;
        }
        if (flag == 0)
            return WRONG_ARG;
    }
    else
    {
        puts("Numbers only policy");
        return WRONG_ARG;
    }
    return OK;
}

int main(int argc, char *argv[N])
{
    if (argc != 2)
        return WRONG_ARG;
    
    float minn, maxn;
    int c = 0;
    int ch;
    float avg = 0;
    FILE *f;
    
    f = fopen(argv[1], "r");
    
    if (f == NULL)
    {
        puts("File doesn't exist");
        return EMPTY_FILE;
    }
    if (min_max(f, &minn, &maxn))
    {
        puts("Something went really wrong..");
        return WRONG_ARG;
    }
    else
    {
        avg = (minn + maxn) / 2;
        if (search(f, avg, &c))
        {
            puts("File doesn't exist");
            return WRONG_ARG;
        }
        else
            printf("%d ", c);
    }
    fclose(f);
}
