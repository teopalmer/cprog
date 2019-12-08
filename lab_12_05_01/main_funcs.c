#include "main_funcs.h"
#include "list_funcs.h"

void print_str(str_t s)
{
    for (int i = 0; i < 4; i++)
    {
        if (s[i] != 0)
            printf("%c", s[i]);
    }
}

void clean_str(str_t s)
{
    for (int i = 0; i < 4; i++)
    {
        s[i] = 0;
    }
}

node_t *get_str_raw()
{
    int i = 0;
    int ch = 0;
    char st[256];
    node_t *h = NULL;
    str_t s = { 0 };
    ch = scanf("%s", st);

    while (ch == 1 && st[i])
    {
        //ch = scanf("%c", &s[i]);
        s[i % 4] = st[i];
        i++;

        if (i % 4 == 0)
        {
            //printf("s: %s\n", s);
            h = push(h, s);
            clean_str(s);
        }
    }

    if (i % 4!= 0)
    {
        h = push(h, s);
    }

    return h->head;
}

node_t *get_str_sps()
{
    int i = 0;
    int ch = 0;
    char st[256];
    int flag = 0;
    node_t *h = NULL;
    str_t s = { 0 };
    ch = scanf("%s", st);

    while (ch == 1 && st[i])
    {
        if ((flag == 0 && st[i] == ' ') || st[i] != ' ')
        {
            s[i % 4] = st[i];
            if (st[i] == ' ')
                flag = 1;
            else
                flag = 0;
        }

        i++;

        if (i % 4 == 0)
        {
            //printf("s: %s\n", s);
            h = push(h, s);
            clean_str(s);
        }
    }

    if (i % 4!= 0)
    {
        h = push(h, s);
    }

    return h->head;
}

void out()
{
    node_t *n = get_str_raw();
    puts("STRING: ");
    while (n != NULL)
    {
        print_str(n->s);
        n = n->next;
    }

}

void cat()
{
    node_t *n1 = get_str_raw();
    node_t *n2 = get_str_raw();
    while (n1 != NULL)
    {
        print_str(n1->s);
        n1 = n1->next;
    }
    while (n2 != NULL)
    {
        print_str(n2->s);
        n2 = n2->next;
    }
}