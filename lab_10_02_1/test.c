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

void fill_items_array(item_t **p, int num)
{
    str_t article = "baby";
    str_t name = "driver";
    int count = 0;
    int c = 0;
    resize_items_array(p, &c, num);
    for (int i = 0; i < num; i++)
    {
        fill_item(&(*p)[i], article, name, count);
    }
    for (int i = 0; i < c; i++)
    {
        free(p[i]->article);
        free(p[i]->name);
    }
}

int main()
{
    item_t a;
    item_t *p = NULL;
    int c = 0;
    int arraysize = 0;
    fill_items_array(&p, 1);
    sort_array(p, arraysize, "count");
    sort_array(p, arraysize, "name");
    sort_array(p, arraysize, "article");
    delete_lipstick(p, &arraysize);
    free(p);
    return 0;
}
