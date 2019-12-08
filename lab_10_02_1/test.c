#include "resizing_items.h"
#include "user_interface.h"
#include "main_funcs.h"
#include "defines.h"
#include <stdarg.h>

void merge_str(char *a, char *b)
{
    while (*a)
        a++;

    while (*b)
    {
        *a = *b;
        b++;
        a++;
    }
    *a = '\0';
}

void my_print_input(item_t item)
{
    puts("\nARTICLE: ");
    printf("%s", item.article);
    puts("\nname: ");
    printf("%s", item.name);
    puts("");
    printf("COUNT: %d", item.count);
}

void my_file_print_input(item_t *p, int arraysize)
{
    //FILE *f = fopen("stockpile.txt", "w");
    for (int i = 0; i < arraysize; i++)
    {
        fprintf(stdout, "%s\n", p[i].article);
        fprintf(stdout, "%s\n", p[i].name);
        fprintf(stdout, "%d\n", p[i].count);
    }
    //fclose(f);
}

void fill_item(item_t *a, str_t article, str_t name, int c)
{
    create_fields(a, strlen(article) + 1, strlen(name) + 1, c);
    strcpy(a->article, article);
    a->size_a = strlen(article);
    strcpy(a->name, name);
    a->size_n = strlen(name);
}

void fill_items_array(item_t **p, int *asize, int num, ...)
{
    //str_t article = "";
    //str_t name = "";
    int count = 0;
    int c = 0;
    va_list l;
    va_start(l, num);
    resize_items_array(p, &c, num);

    for (int i = 0; i < num; i++)
    {
        puts("");
        char *a = va_arg(l, char*);
        char *n = va_arg(l, char*);
        printf("article: %s", a);
        count = va_arg(l, int);
        fill_item(&(*p)[i], a, n, count);
        (*asize)++;
    }
    va_end(l);
}

int test_single()
{
    item_t *p = NULL;
    int arraysize = 0;
    int flag = 0;
    fill_items_array(&p, &arraysize, 1, "AMY", "LUCAS", 2);
    sort_array(p, arraysize, "count");
    sort_array(p, arraysize, "name");
    sort_array(p, arraysize, "article");
    delete_lipstick(p, &arraysize);
    if (arraysize == 1)
        flag = 1;
    clear(&p, arraysize);
    return flag;
}

int test_ordinary()
{
    item_t *p = NULL;
    int arraysize = 0;
    int flag = ok;
    fill_items_array(&p, &arraysize, 3, "AMY", "LUCAS", 2, "LIP", "STIck", 0, "LIP", "STICK", 12);
    sort_array(p, arraysize, "count");
    sort_array(p, arraysize, "name");
    sort_array(p, arraysize, "article");
    delete_lipstick(p, &arraysize);
    if (arraysize != 2)
        flag = 1;
    clear(&p, arraysize);
    return flag;
}

int test_same()
{
    item_t *p = NULL;
    int arraysize = 0;
    int flag = ok;
    fill_items_array(&p, &arraysize, 3, "LIP", "STIck", 0, "LIP", "STIck", 0, "LIP", "sTICK", 0);
    delete_lipstick(p, &arraysize);
    sort_array(p, arraysize, "COUNT");
    sort_array(p, arraysize, "NAME");
    sort_array(p, arraysize, "ARTICLE");
    if (arraysize != 2)
        flag = 1;
    clear(&p, arraysize);
    return flag;
}


int main()
{
    int all = 0;
    all += test_ordinary();
    all += test_same();
    all += test_single();
    printf("%d out of 3", all);
    if (all != 3)
    {
        puts("ERROR");
        return 1;
    }
    return 0;
}
