#include "defines.h"
#include "main_funcs.h"
#include "resizing_items.h"
#include "user_interface.h"

int stricmp(const char *a, const char *b)
{
    int ca, cb;
    do {
        ca = (unsigned char) *a++;
        cb = (unsigned char) *b++;
        ca = tolower(toupper(ca));
        cb = tolower(toupper(cb));
    } while (ca == cb && ca != '\0');
    return ca - cb;
}

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

    if (stricmp(key, "ARTICLE") == 0)
    {
        qsort(p, (size_t)arraysize, sizeof(item_t), compare_articles);
        return ok;
    }

    if (stricmp(key, "NAME") == 0)
    {
        qsort(p, (size_t)arraysize, sizeof(item_t), compare_names);
        return ok;
    }

    if (stricmp(key, "COUNT") == 0)
    {
        qsort(p, (size_t)arraysize, sizeof(item_t), compare_count);
        return ok;
    }

    puts("NO!");
    return input_error;
}
