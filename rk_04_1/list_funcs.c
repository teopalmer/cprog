#include "defines.h"
#include "list_funcs.h"
#include "user_interface.h"

node_t *push(node_t *tail, data_t data)
{
    node_t *n = calloc(1, sizeof(node_t));

    if (tail != NULL)
    {
        tail->next = n;
    }

    n->next = NULL;
    n->data = data;

    return n;
}

node_t *get_adress(node_t *n, int i)
{
    for (int a = 0; a < i; a++)
    {
        n = n->next;
    }
    print_list(n);
    return n;
}

node_t *get_place(node_t *n, data_t data)
{
    int i = 0;

    if (n == NULL)
    {
        puts("*");
        return n;
    }

    puts("Not empty");

    while (n != NULL)
    {
        puts("*1");
        if (n->data.popul > data.popul)
            return get_adress(n, i);
        n = n->next;
        puts("*2");
        i++;
    }

    return get_adress(n, i);
}

