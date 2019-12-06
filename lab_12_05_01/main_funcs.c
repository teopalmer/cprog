#include "main_funcs.h"
#include "list_funcs.h"

node_t *get_str_raw()
{
    int i = 0;
    int ch = 0;
    node_t *h = NULL;
    str_t s = { 'a' };
    ch = scanf("%c", &s[i]);

    do
    {
        ch = scanf("%c", &s[i]);
        i++;

        if (i == 4)
        {
            //puts("*");
            printf("%s %d", s, i);
            h = push(h, s);
            i = 0;
        }

    } while (ch == 1 && );

    if (i != 0)
    {
        printf("%s %d", s, i);
        h = push(h, s);
    }

    return h->head;
}

void out()
{
    node_t *n = get_str_raw();
    do
    {
        printf("THE STRING: %s", n->s);
        n = n->next;
    } while (n != NULL);

}