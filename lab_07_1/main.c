#include <stdio.h>
#include <string.h>

#define OK 0
#define VALUE_ERROR 4
#define ARGUMENTS_ERROR 53
#define FILE_ERROR 5
#define N 256
#define eps 0.001
typedef char str_t[N];

typedef struct {
    char surname[25];
    char name[10];
    unsigned int marks[4];
}Student;

int read_student(FILE *f, Student *stud)
{
    int ch1, ch2, ch3;
    ch1 = fscanf(f, "%s", stud->surname);
    ch2 = fscanf(f, "%s", stud->name);
    for (int i = 0; i < 4; i++)
    {
        ch3 = fscanf(f, "%u", &stud->marks[i]);
        if (ch1!=1 || ch2 != 1 || ch3 != 1)
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

void sort_students(Student class[N], int n)
{
    for (int ik = 0; ik < n; ik++)
    {
        for (int i = n - 1; i >= ik; i--)
        {
            if (class[i].surname[0] > class[i + 1].surname[0])
            {
                Student tmp = class[i];
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
                Student tmp = class[j];
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
    
    return OK;
}

int sort_mode(str_t filename)
{
    int n = 0;
    Student class[N];
    FILE *f = fopen(filename, "r");
    
    if (check_file(f))
    return FILE_ERROR;
    
    while (!read_student(f, &class[n]))
    n++;
    
    n--;
    
    sort_students(class, n);
    
    for (int i = 0; i < n; i++)
    printf("%s\n%s\n%u %u %u %u\n", class[i].surname, class[i].name,
           class[i].marks[0], class[i].marks[1],
           class[i].marks[2], class[i].marks[3]);
    
    return 0;
}

int substr_mode(str_t fname_in, str_t fname_out, str_t s)
{
    Student class[N];
    int n = 0;
    
    FILE *f_in = fopen(fname_in, "r");
    FILE *f_out = fopen(fname_out, "w");
    
    if (check_file(f_in) || check_file(f_out))
    return FILE_ERROR;
    
    while (!read_student(f_in, &class[n]))
    {
        if (strstr(class[n].surname, s) == class[n].surname)
        fprintf(f_out, "%s\n%s\n%u %u %u %u\n", class[n].surname,
                class[n].name, class[n].marks[0], class[n].marks[1],
                class[n].marks[2], class[n].marks[3]);
        n++;
    }
    
    return 0;
}

int grade_mode(str_t filename)
{
    Student class[N];
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
        printf(" avnow: %f ", av[n]);
        n++;
    }
    
    for (int i = 0; i < n; i++)
        f_av += av[i];
    f_av /= n;
    
    printf(" avfnow: %f ", f_av);
    
    fclose(f);
    f = fopen(filename, "w");
    
    for (int i = 0; i < n; i++)
    {
        if (av[i] + eps >= f_av)
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
    
    else if (!strcmp(mode, "ft"))
    return substr_mode(argv[2], argv[3], argv[4]);
    
    else if (!strcmp(mode, "dt"))
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
