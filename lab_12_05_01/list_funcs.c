#include "list_funcs.h"

/*node_t *init(int a) // а- значение первого узла
{
    node_t *lst;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->str = a;
    lst->next = NULL; // это последний узел списка
    return(lst);
}*/

static void fill_s(node_t *node, const str_t s)
{
    for (int i = 0; i < 4; i ++)
    {
        node->s[i] = s[i];
        i++;
    }
}

node_t *push(node_t *tail, str_t s)
{
    node_t *node = calloc(1, sizeof(node_t));
    fill_s(node, s);

    if (tail == NULL)
    {
        node->head = node;
    }
    else
    {
        node->head = tail->head;
        tail->next = node;
    }
    node->next = NULL;
    return node;
}
