#include "user_interface.h"
#include "list_funcs.h"

node_t *get_input(node_t *n)
{
    data_t data;
    node_t *h = NULL;

    int i = 0;

    while (strcmp(data.name, "end") != 0)
    {
        scanf("%s", data.name);

        if (strcmp(data.name, "end") == 0)
            return h;

        scanf("%s %s %d %d", data.region, data.okrug, &data.popul, &data.year);

        if (i == 0)
        {
            h = push(h, data);
            n = h;
        }

        else
        {
            n = push(n, data);
        }

        i++;
    }

    return h;
}

void print_list(node_t *n)
{
    str_t name;
    str_t region;
    str_t okrug;
    int popul;
    int year;

    while (n != NULL)
    {
        strcpy(name, n->data.name);
        strcpy(region, n->data.region);
        strcpy(okrug, n->data.okrug);
        popul = n->data.popul;
        year = n->data.year;

        printf("%s\n%s\n%s\n%d\n%d\n", name, region, okrug, popul, year);
        n = n->next;
    }
    puts("end");
}