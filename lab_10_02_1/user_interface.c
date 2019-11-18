#include "user_interface.h"
#include "defines.h"
#include "resizing_items.h"
#include "main_funcs.h"

static int scan_string(long int *len, str_t s)
{
    int ch = scanf("%s", s);
    if (ch != 1)
        return input_error;
    *len = strlen(s) + 1;
    return ok;
}

static int scan_number(int *d)
{
    int ch = scanf("%d", d);
    if (ch != 1)
        return input_error;
    if (*d < 0)
        return input_error;
    return ok;
}

static int check_if_upper(char c)
{
    if (c > 'Z' || c < 'A')
        return input_error;
    return ok;
}

static int check_if_int(char c)
{
    if (c <= '9' && c >= '0')
        return input_error;
    return ok;
}

int get_key(str_t key)
{
    puts("Enter key for sorting:");
    int ch = scanf("%s", key);
    if (ch != 1)
        return input_error;
    return ok;
}

static int fill_article(item_t *item, str_t article)
{
    long int len = strlen(article);

    for (int i = 0; i < len; i++)
    {
        if (check_if_int(article[i]) != ok)
            return input_error;

        if (check_if_upper(article[i]) != ok)
            return input_error;

        item->article[i] = article[i];
    }
    return ok;
}

static int fill_name(item_t *item, str_t name)
{
    long int len = strlen(name);

    for (int i = 0; i < len; i++)
    {
        if (check_if_int(name[i]) != ok)
            return input_error;

        item->name[i] = name[i];
    }

    strcat(item->article, item->name);

    return ok;
}

static int scan_input(item_t *item, str_t article, str_t name, int *c)
{
    puts("\nEnter article:");
    if (scan_string(&item->size_a, article) != ok)
        return input_error;

    if (stricmp("nothing", article) == 0)
        return article_nothing;

    long int len = strlen(article);

    for (int i = 0; i < len; i++)
    {
        if (check_if_int(article[i]) != ok)
            return input_error;

        if (check_if_upper(article[i]) != ok)
            return input_error;
    }

    puts("Enter name:");
    if (scan_string(&item->size_n, name) != ok)
    {
        return input_error;
    }

    len = strlen(name);

    for (int i = 0; i < len; i++)
    {
        if (check_if_int(name[i]) != ok)
            return input_error;
    }

    puts("Enter quantity:");
    if (scan_number(c) != ok)
    {
        return input_error;
    }

    return ok;
}

static int fill_input(item_t *item)
{
    str_t article;
    str_t name;
    int c;

    int scan_out = scan_input(item, article, name, &c);

    if (scan_out != ok)
        return scan_out;

    if (create_fields(item, item->size_a, item->size_n, c) != ok)
        return memory_error;

    if (fill_article(item, article) != ok)
        return input_error;

    if (fill_name(item, name) != ok)
        return input_error;
    
    item->size_a += item->size_n;
    
    for (int i = 0; i < item->size_a; i++)
        item->article[i] = toupper(item->article[i]);

    item->count = c;

    return ok;
}

int full_input(int *array_size, item_t **p)
{
    int i = 0;
    int input_out = ok;
    int full_out = ok;

    while (input_out == ok && full_out == ok)
    {
        full_out = resize_items_array(p, array_size, ADD);
        input_out = fill_input(&(*p)[i]);
        i++;
    }
    (*array_size)--;

    if (array_size < 0 || input_out != article_nothing)
    {
        /*for (int in = 0; in < *array_size; in++)
        {
            free((*p)[in].article);
            free((*p)[in].name);
        }
        free(*p);*/
        //(*array_size)--;
        return input_error;
    }

    //(*array_size)--;

    return ok;
}

void print_input(item_t item)
{
    puts("\nArticle: ");
    printf("%s", item.article);
    puts("\nName: ");
    printf("%s", item.name);
    puts("");
    printf("Count: %d", item.count);
}

void file_print_input(item_t *p, int arraysize)
{
    FILE *f = fopen("stockpile.txt", "w");
    for (int i = 0; i < arraysize; i++)
    {
        fprintf(f, "%s\n", p[i].article);
        fprintf(f, "%s\n", p[i].name);
        fprintf(f, "%d\n", p[i].count);
    }
    fclose(f);
}
