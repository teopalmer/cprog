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

int print_str_sps(str_t s, int flag)
{
    for (int i = 0; i < 4; i++)
    {
        if (s[i] != 0)
        {
            if (s[i] != ' ' || flag == 0)
            {
                printf("%c", s[i]);
                if (s[i] == ' ')
                    flag = 1;
                else
                    flag = 0;
            }
        }
    }
    return flag;
}

int compare_str(node_t *n1, str_t n2, int n)
{
    int in1 = n;
    int in2 = 0;
    int lmax = strlen(n2);
    while (n1 != NULL && n2 != NULL)
    {
        if (n1->s[in1] != n2[in2] && (in2 < lmax) && (n1->s[in1]))
        {
            //printf("f: %c %c\n", n1->s[in1], n2[in2]);
            return 1;
        }
        else
        {
            //printf("y: %c %c\n", n1->s[in1], n2[in2]);
            if (in1 == 3)
            {
                in1 = -1;
                n1 = n1->next;
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
    char st = 0;
    node_t *h = NULL;
    str_t s = { 0 };
    ch = scanf("%c", &st);

    if (st == '\n')
    {
        delete_list(h);
        return NULL;
    }

    while (ch == 1 && st != '\n')
    {
        s[i % 4] = st;
        i++;

        if (i % 4 == 0)
        {
            h = push(h, s);
            clean_str(s);
        }
        ch = scanf("%c", &st);
    }

    if (i % 4 != 0)
    {
        h = push(h, s);
    }

    if (h == NULL)
        return NULL;

    return h->head;
}
