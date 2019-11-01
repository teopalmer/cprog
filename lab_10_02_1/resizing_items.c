#include "resizing_items.h"
#include "user_interface.h"
#include "defines.h"

int create_fields(item_t *item, long int sizeA, long int sizeN, int c)
{
    char *newA = malloc((sizeA + sizeN) * sizeof(char));
    char *newN = malloc(sizeN * sizeof(char));

    if (!newA || !newN)
    {
        return MEMORY_ERROR;
    }
    else
    {
        item->article = newA;
        item->name = newN;
        item->count = c;
    }
    return OK;
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
        return DELETION_ERROR;

    item_t *pnew = (item_t*)realloc(*p, (*num) * sizeof(item_t));

    if (pnew == NULL)
        return MEMORY_ERROR;

    *p = pnew;
    return OK;
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