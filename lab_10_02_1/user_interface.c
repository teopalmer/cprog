#include "user_interface.h"
#include "defines.h"
#include "resizing_items.h"

static int scan_string(long int *len, str_t s)
{
    int ch = scanf("%s", s);
    if (ch != 1)
        return INPUT_ERROR;
    *len = strlen(s) + 1;
    return OK;
}

static int scan_number(int *d)
{
    int ch = scanf("%d", d);
    if (ch != 1)
        return INPUT_ERROR;
    return OK;
}

static int check_if_upper(char c)
{
    if (c > 'Z' || c < 'A')
        return INPUT_ERROR;
    return OK;
}

static int check_if_int(char c)
{
    if (c <= '9' && c >= '0')
        return INPUT_ERROR;
    return OK;
}

int get_key(str_t key)
{
    puts("Enter key for sorting:");
    int ch = scanf("%s", key);
    if (ch != 1)
        return INPUT_ERROR;
    return OK;
}

int fill_article(item_t *item, str_t article)
{
    long int len = strlen(article);

    for (int i = 0; i < len; i++)
    {
        if (check_if_int(article[i]) != OK)
            return INPUT_ERROR;

        if (check_if_upper(article[i]) != OK)
            return INPUT_ERROR;

        item->article[i] = article[i];
    }
    return OK;
}

int fill_name(item_t *item, str_t name)
{
    long int len = strlen(name);

    for (int i = 0; i < len; i++)
    {
        if (check_if_int(name[i]) != OK)
            return INPUT_ERROR;

        item->name[i] = name[i];
    }

    strcat(item->article, item->name);

    return OK;
}

int scan_input(item_t *item, str_t article, str_t name, int *c)
{
    puts("\nEnter article:");
    if (scan_string(&item->sizeA, article) != OK)
        return INPUT_ERROR;

    if (strcmp("nothing", article) == 0)
        return ARTICLE_NOTHING;

    puts("Enter name:");
    if (scan_string(&item->sizeN, name) != OK)
    {
        return INPUT_ERROR;
    }

    puts("Enter quantity:");
    if (scan_number(c) != OK)
    {
        return INPUT_ERROR;
    }

    return OK;
}

int fill_input(item_t *item)
{
    str_t article;
    str_t name;
    int c;

    int scan_out = scan_input(item, article, name, &c);

    if (scan_out != OK)
        return scan_out;

    if (create_fields(item, item->sizeA, item->sizeN, c) != OK)
        return MEMORY_ERROR;

    if (fill_article(item, article) != OK)
        return INPUT_ERROR;

    if (fill_name(item, name) != OK)
        return INPUT_ERROR;

    item->count = c;

    return OK;
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