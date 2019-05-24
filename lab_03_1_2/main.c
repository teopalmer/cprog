#include <stdio.h>
#define OK 0
#define WRONG_ARG 2
#define EMPTY_FILE 3
#define FILE_ERROR 4

int search(FILE *f, float avg, int *q)
{
    float t;
    rewind(f);
    while (fscanf(f, "%f", &t) == 1)
    {
        if (t > avg)
            (*q)++;
    }
    if (q == 0)
        return WRONG_ARG;
    return OK;
}

int min_max(FILE *f, float *min_num, float *max_num)
{
    float t;
    int flag = 0;
    if (fscanf(f, "%f", min_num) == 1)
    {
        if (fscanf(f, "%f", &t) == 1)
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
        return WRONG_ARG;
    return OK;
}

int main(int argc, char *argv[])
{
    float min_num, max_num;
    int q = 0;
    int check;
    FILE *f;
    /*if (argc != 2)
     return WRONG_ARG;*/
    f = fopen(argv[1], "r");
    if (f == NULL)
        return EMPTY_FILE;
    check = min_max(f, &min_num, &max_num);
    
    if (check)
    {
        return WRONG_ARG;
    }
    else
    {
        float avg = (min_num + max_num) / 2;
        check = search(f, avg, &q);
        if (check)
            return FILE_ERROR;
        else
            printf("%d ", q);
    }
    fclose(f);
}
