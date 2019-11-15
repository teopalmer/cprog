#include "user_interface.h"
#include "defines.h"
#include "resizing_items.h"

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

int fill_article(item_t *item, str_t article)
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

int fill_name(item_t *item, str_t name)
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

int scan_input(item_t *item, str_t article, str_t name, int *c)
{
    puts("\nEnter article:");
    if (scan_string(&item->size_a, article) != ok)
        return input_error;

    if (strcmp("nothing", article) == 0)
        return article_nothing;

    puts("Enter name:");
    if (scan_string(&item->size_n, name) != ok)
    {
        return input_error;
    }

    puts("Enter quantity:");
    if (scan_number(c) != ok)
    {
        return input_error;
    }

    return ok;
}

int fill_input(item_t *item)
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

    item->count = c;

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
