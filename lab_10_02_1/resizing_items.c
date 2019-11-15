#include "resizing_items.h"
#include "user_interface.h"
#include "defines.h"

int create_fields(item_t *item, long int size_a, long int size_n, int c)
{
    char *newa = calloc((size_a + size_n), sizeof(char));
    char *newn = calloc(size_n, sizeof(char));

    if (!newa || !newn)
    {
        return memory_error;
    }
    else
    {
        item->article = newa;
        item->name = newn;
        item->count = c;
    }
    return ok;
}

void remove_item(item_t *p, int n, int fullsize)
{
    free(p[n].article);
    free(p[n].name);
    for (int i = n; i < fullsize - 1; i++)
    {
        p[i] = p[i + 1];
    }
}

int resize_items_array(item_t **p, int *num, int flag)
{
    *num += flag;

    if (*num < 0)
        return deletion_error;

    item_t *pnew = (item_t*)realloc(*p, (*num) * sizeof(item_t));

    if (pnew == NULL)
        return memory_error;

    *p = pnew;
    return ok;
}

void clean(item_t **p, int arraysize)
{
    for (int i = 0; i < arraysize; i++)
    {
        free(p[i]->article);
        free(p[i]->name);
    }
    free(p);
}
