#include "main_funcs.h"
#include "list_funcs.h"

node_t *get_str_raw()
{
    int i = 0;
    int ch = 0;
    node_t *h = NULL;
    str_t s;
    do
    {
        ch = scanf("%c", &s[i]);
        i++;

        if (i == 3)
        {
            h = push(h, s);
        }

    } while (s[i] != '\0' && ch == 1);

    return h->head;
}

void out()
{
    node_t *n = get_str_raw();
    do
    {
        printf("%s", n->s);
        n = n->next;
    } while (n != NULL);

}