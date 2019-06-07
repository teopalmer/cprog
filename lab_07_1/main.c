#include <stdio.h>
#include <string.h>

#define OK 0
#define VALUE_ERROR 4
#define ARGUMENTS_ERROR 53
#define FILE_ERROR 5
#define N 10
#define EPS 0.001
typedef char str_t[N];

typedef struct
{
    char surname[25];
    char name[10];
    unsigned int marks[4];
} student;

int read_student(FILE *f, student *stud)
{
    int ch1, ch2, ch3;
    strcpy(stud->surname, "surname");
    strcpy(stud->name, "name");
    for (int i = 0; i < 4; i++)
        stud->marks[i] = 0;
    ch1 = fscanf(f, "%s", stud->surname);
    ch2 = fscanf(f, "%s", stud->name);
    for (int i = 0; i < 4; i++)
    {
        ch3 = fscanf(f, "%u", &stud->marks[i]);
        if (ch1 != 1 || ch2 != 1 || ch3 != 1)
        return VALUE_ERROR;
    }
    return OK;
}

int check_arguments(int argc)
{
    if (argc < 3)
    {
        puts("Recheck your arguments");
        return ARGUMENTS_ERROR;
    }
    
    return OK;
}

void sort_students(student class[N], int n)
{
    for (int ik = 0; ik < n; ik++)
    {
        for (int i = n - 1; i >= ik; i--)
        {
            if (class[i].surname[0] > class[i + 1].surname[0])
            {
                student tmp = class[i];
                class[i] = class[i + 1];
                class[i + 1] = tmp;
            }
        }
    }
    
    for (int jk = 0; jk < n; jk++)
    {
        for (int j = n - 1; j >= jk; j--)
        {
            if (class[j].name[0] > class[j + 1].name[0] &&
                class[j].surname[0] == class[j + 1].surname[0])
            {
                student tmp = class[j];
                class[j] = class[j + 1];
                class[j + 1] = tmp;
            }
        }
    }
}

int check_file(FILE *f)
{
    if (!f)
    {
        puts("File is not found");
        return FILE_ERROR;
    }
    if (fgetc(f) == EOF)
    {
        return VALUE_ERROR;
    }
    else
        rewind(f);
    return OK;
}

int sort_mode(str_t filename)
{
    int n = 0;
    student class[N];
    FILE *f = fopen(filename, "r");
    
    if (check_file(f))
        return FILE_ERROR;
    
    while (!read_student(f, &class[n]))
        n++;
    if (n == 0)
    {
        puts("File is empty tho..");
        return VALUE_ERROR;
    }
    
    n--;
    
    sort_students(class, n);
    
    for (int i = 0; i < n+1; i++)
        printf("%s\n%s\n%u %u %u %u\n", class[i].surname, class[i].name,
            class[i].marks[0], class[i].marks[1],
            class[i].marks[2], class[i].marks[3]);
    fclose(f);
    
    return 0;
}

int substr_mode(str_t fname_in, str_t fname_out, str_t s)
{
    student class[N];
    int n = 0;
    int c = 0;
    
    FILE *f_in = fopen(fname_in, "r");
    FILE *f_out = fopen(fname_out, "w");
    
    if (check_file(f_in) || check_file(f_out) == FILE_ERROR)
        return FILE_ERROR;
    
    while (!read_student(f_in, &class[n]))
    {
        if (strstr(class[n].surname, s) == class[n].surname)
        {
            fprintf(f_out, "%s\n%s\n%u %u %u %u\n", class[n].surname,
                    class[n].name, class[n].marks[0], class[n].marks[1],
                    class[n].marks[2], class[n].marks[3]);
            c++;
        }
        n++;
    }
    if (n == 0 || c == 0)
    {
        puts("File is empty tho..");
        return VALUE_ERROR;
    }
    
    fclose(f_in);
    fclose(f_out);
    return 0;
}

int grade_mode(str_t filename)
{
    student class[N];
    int n = 0;
    float av[N];
    float f_av = 0;
    
    FILE *f = fopen(filename, "r");
    
    if (check_file(f))
        return FILE_ERROR;
    
    while (!read_student(f, &class[n]))
    {
        for (int i = 0; i < 4; i++)
            av[n] += class[n].marks[i];
        av[n] /= 4;
        n++;
    }
    
    if (n == 0)
    {
        puts("File is empty tho..");
        return VALUE_ERROR;
    }
    
    for (int i = 0; i < n; i++)
        f_av += av[i];
    f_av /= n;
    
    fclose(f);
    f = fopen(filename, "w");
    
    for (int i = 0; i < n; i++)
    {
        if (av[i] + EPS >= f_av)
            fprintf(f, "%s\n%s\n%u %u %u %u\n", class[i].surname,
                class[i].name, class[i].marks[0], class[i].marks[1],
                class[i].marks[2], class[i].marks[3]);
    }
    fclose(f);
    return 0;
}

int check_regime(char *argv[])
{
    str_t mode;
    strcpy(mode, argv[1]);
    
    if (!strcmp(mode, "st"))
        return (sort_mode(argv[2]));
    
    if (!strcmp(mode, "ft"))
        return substr_mode(argv[2], argv[3], argv[4]);
    
    if (!strcmp(mode, "dt"))
        return grade_mode(argv[2]);
    else
    {
        puts("Check yout arguments");
        return ARGUMENTS_ERROR;
    }
}

int main(int argc, char *argv[])
{
    if (check_arguments(argc))
        return ARGUMENTS_ERROR;
    
    return check_regime(argv);
}
