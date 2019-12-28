#include "list_funcs.h"
#include "main_funcs.h"

node_t *push(node_t *tail, str_t s)
{
    node_t *node = calloc(1, sizeof(node_t));
    strcpy(node->s, s);
    //print_str(node->s);

    if (tail != NULL)
    {
        node->head = tail->head;
        tail->next = node;
    }
    else
    {
        node->head = node;
    }
    node->next = NULL;
    return node;
}

void delete_list(node_t *n)
{
    node_t *p = NULL;
    while (n != NULL)
    {
        p = n->next;
        free(n);
        n = p;
    }
    free(p);
}
