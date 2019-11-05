#include "defines.h"
#include "main_funcs.h"
#include "resizing_items.h"
#include "user_interface.h"

static int compare_articles(const void *a, const void *b)
{
    item_t *ia = (item_t *)a;
    item_t *ib = (item_t *)b;
    return strcmp(ia->article, ib->article);
}

static int compare_names(const void *a, const void *b)
{
    item_t *ia = (item_t *)a;
    item_t *ib = (item_t *)b;
    return strcmp(ia->name, ib->name);
}

static int compare_count(const void *a, const void *b)
{
    item_t *ia = (item_t *)a;
    item_t *ib = (item_t *)b;
    return (ia->count - ib->count);
}

int delete_lipstick(item_t *p, int *arraysize)
{
    for (int i = 0; i < *arraysize; i++)
    {
        if ((strcmp("LIPSTICK", p[i].article) == 0) && (p[i].count == 0))
        {
            remove_item(p, i, *arraysize);
            (*arraysize)--;
            i--;
        }
    }

    return ok;
}

int sort_array(item_t *p, int arraysize, str_t key)
{
    if (arraysize == 0)
        return deletion_error;

    if (strcmp(key, "ARTICLE") == 0 || strcmp(key, "article") == 0)
    {
        qsort(p, (size_t)arraysize, sizeof(item_t), compare_articles);
        return ok;
    }

    if (strcmp(key, "NAME") == 0 || strcmp(key, "name") == 0)
    {
        qsort(p, (size_t)arraysize, sizeof(item_t), compare_names);
        return ok;
    }

    if (strcmp(key, "COUNT") == 0 || (strcmp(key, "count") == 0))
    {
        qsort(p, (size_t)arraysize, sizeof(item_t), compare_count);
        return ok;
    }

    puts("NO!");
    return input_error;
}
