#include "resizing_items.h"
#include "user_interface.h"
#include "main_funcs.h"
#include "defines.h"
#include <stdarg.h>

void my_print_input(item_t item)
{
    puts("\nArticle: ");
    printf("%s", item.article);
    puts("\nName: ");
    printf("%s", item.name);
    puts("");
    printf("Count: %d", item.count);
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

void fill_items_array(item_t **p, int num, ...)
{
    str_t article;
    str_t name;
    int count = 0;
    int c = 0;
    va_list l;

    resize_items_array(p, &c, num);

    va_start(l, num);
    for (int i = 0; i < num; i++)
    {
        printf("farg: %s", va_arg(l, str_t));
        strcpy(article, va_arg(l, str_t));
        printf("article: %s name: %s", article, name);
        count = va_arg(l, int);
        fill_item(&(*p)[i], article, name, count);
    }
    va_end(l);
    for (int i = 0; i < c; i++)
    {
        free(p[i]->article);
        free(p[i]->name);
    }
}

int item_comparison (item_t **p, int psize, item_t **res, int ressize)
{
    if (psize != ressize)
        return input_error;
    return ok;
}
int test_removal(item_t a)
{
    item_t **res = NULL;
    fill_items_array(res, 2, "LIP", "STICK", 3, "MARY", "JANE", 10);

    return ok;
}

int main()
{
    item_t a;
    item_t *p = NULL;
    int c = 0;
    int arraysize = 0;
    fill_items_array(&p, 1, "AMY", "LUCAS", 2);
    //my_file_print_input(p, 2);
    free(p);
    return 0;
}
