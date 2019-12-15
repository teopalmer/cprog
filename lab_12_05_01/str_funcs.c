#include "str_funcs.h"
#include "list_funcs.h"

void print_str(str_t s)
{
    for (int i = 0; i < 4; i++)
    {
        if (s[i] != 0)
            printf("%c", s[i]);
    }
}

int compare_str(node_t *n1, node_t *n2, int n)
{
    int in1 = n;
    int in2 = 0;
    while (n1 != NULL && n2 != NULL)
    {
        if (n1->s[in1] != n2->s[in2] && (n2->s[in2]) && (n1->s[in1]))
        {
            return 1;
        }
        else
        {
            if (in1 >= 3)
            {
                in1 = 0;
                n1 = n1->next;
            }
            if (in2 >= 3)
            {
                in2 = 0;
                n2 = n2->next;
            }
            in1++;
            in2++;
        }
    }

    return 0;
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
    ch = scanf("\n%[^\n]", st);

    while (ch == 1 && st[i])
    {
        s[i % 4] = st[i];
        i++;

        if (i % 4 == 0)
        {
            h = push(h, s);
            clean_str(s);
        }
    }

    if (i % 4 != 0)
    {
        h = push(h, s);
    }

    if (h == NULL)
        return NULL;

    return h->head;
}

node_t *get_str_sps()
{
    int i = 0;
    int k = 0;
    int ch = 0;
    char st[256];
    int flag = 0;
    node_t *h = NULL;
    str_t s = { 0 };
    ch = scanf("\n%[^\n]", st);

    while (ch == 1 && st[i])
    {
        if ((flag == 0 && st[i] == ' ') || st[i] != ' ')
        {
            s[k] = st[i];
            if (st[i] == ' ')
                flag = 1;
            else
                flag = 0;
            k++;
        }

        i++;

        if (i % 4 == 0)
        {
            //printf("s: %s\n", s);
            h = push(h, s);
            clean_str(s);
            k = 0;
        }
    }

    if (i % 4 != 0)
    {
        h = push(h, s);
    }

    if (h == NULL)
        return NULL;

    return h->head;
}
