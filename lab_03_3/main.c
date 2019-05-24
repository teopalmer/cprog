#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define OK 0
#define WRONG_ARG 2
#define EMPTY_FILE 3
#define FILE_ERROR 4
#define EXECUTION_ERROR 5
#define SIZE 20
#define N 100

int get_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int rez = ftell(f);
    fseek(f, 0, SEEK_SET);
    return (rez / sizeof(int));
}

int get_size_by_name(char filename[N])
{
    FILE *f = fopen(filename, "rb");
    int rez = get_size(f);
    fclose(f);
    return rez;
}

void gen_file(FILE *f)
{
    int n;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        n = rand() % 1000;
        fwrite(&n, sizeof(int), 1, f);
    }
}

void print_file(FILE *f)
{
    int n;
    int size = get_size(f);
    for (int i = 0; i < size; i++)
    {
        fread(&n, sizeof(int), 1, f);
        printf("%d ", n);
    }
    puts("");
}

int get_number_by_pos(char filename[N], int n)
{
    int tmp = 0;
    size_t read;
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        puts("File is empty tho..");
        return EMPTY_FILE;
    }
    for (int i = 0; i < n; i++)
    {
        read = fread(&tmp, sizeof(int), 1, f);
        if (read != 1)
        {
            puts("File is empty  tho..");
            return WRONG_ARG;
        }
    }
    fclose(f);
    return tmp;
}

int put_number_by_pos(char filename[N], int n, int tmp)
{
    FILE *f = fopen(filename, "rb+");
    size_t wr;
    if (!f)
    {
        puts("file is still impty tho..");
        return EMPTY_FILE;
    }
    fseek(f, sizeof(int) * (n - 1), 0);
    wr = fwrite(&tmp, sizeof(int), 1, f);
    if (wr != 1)
    {
        puts("file is still impty tho..");
        return WRONG_ARG;
    }
    fclose(f);
    return OK;
}

void insertsort (double *a, int n)
{
    double x; int i, j;
    for (i=0; i < n; i++)
    {
        x = a[i];
        for (j=i-1; j>=0 && a[j]>x; j--)
            a[j+1] = a[j];
        a[j+1] = x;
    }
}

int sort_file(char filename[N])
{
    int size = get_size_by_name(filename);
    if (size == 0)
        return WRONG_ARG;
    int mas[N];
    for (int i = 1; i <= size; i++)
    {
        mas[i - 1] = get_number_by_pos(filename, i);
        if (mas[i - 1] == WRONG_ARG)
            return WRONG_ARG;
    }
    
    insertsort(mas, size - 1);
    
    for (int i = 1; i <= size; i++)
    {
        if (put_number_by_pos(filename, i, mas[i - 1]) != 0)
            return WRONG_ARG;
    }
    
    return OK;
}

int main(int argc, char **argv)
{
    FILE *file;
    
    if (argc != 3)
        return WRONG_ARG;
    
    for (int i = 1; i < argc; i += 2)
    {
        if (!strcmp(argv[i], "g"))
        {
            file = fopen(argv[i + 1], "wb");
            if (!file)
                return WRONG_ARG;
            gen_file(file);
            fclose(file);
        }
        if (!strcmp(argv[i], "s"))
        {
            if (sort_file(argv[i + 1]) != 0)
                return WRONG_ARG;
        }
        if (!strcmp(argv[i], "p"))
        {
            file = fopen(argv[i + 1], "rb");
            if (!file || get_size(file) == 0)
                return WRONG_ARG;
            print_file(file);
            fclose(file);
        }
        else
        {
            return WRONG_ARG;
        }
    }
    return OK;
}
