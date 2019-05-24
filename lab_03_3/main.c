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
    srand(time(NULL));
    int n;
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
    FILE *f = fopen(filename, "rb");
    size_t read;
    if (!f)
    {
        fclose(f);
        return EMPTY_FILE;
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        read = fread(&tmp, sizeof(int), 1, f);
        if (read != 1)
        {
            fclose(f);
            return EMPTY_FILE;
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
        fclose(f);
        return EMPTY_FILE;
    }
    fseek(f, sizeof(int) * (n - 1), 0);
    wr = fwrite(&tmp, sizeof(int), 1, f);
    if (wr != 1)
    {
        fclose(f);
        return WRONG_ARG;
    }
    fclose(f);
    return OK;
}

void quick_sort(int *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quick_sort(numbers, left, pivot - 1);
    if (right > pivot)
        quick_sort(numbers, pivot + 1, right);
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
    
    quick_sort(mas, 0, size - 1);
    
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
        else
        {
            if (!strcmp(argv[i], "s"))
            {
                if (sort_file(argv[i + 1]) != 0)
                    return WRONG_ARG;
            }
            else
            {
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
        }
    }
    return OK;
}
