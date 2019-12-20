#include "main_funcs.h"
#include "list_funcs.h"
#include "str_funcs.h"
#include "string.h"

int out()
{
    node_t *n = get_str_raw();
    node_t *head = n->head;

    while (n != NULL)
    {
        print_str(n->s);
        n = n->next;
    }

    delete_list(head);
    return ok;
}

int cat()
{
    node_t *n1 = get_str_raw();
    node_t *head1 = n1->head;
    node_t *n2 = get_str_raw();
    node_t *head2 = n2->head;

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
    delete_list(head1);
    delete_list(head2);
    return ok;
}

int sps()
{
    node_t *n = get_str_sps();
    node_t *h = n->head;

    while (n != NULL)
    {
        print_str(n->s);
        n = n->next;
    }
    delete_list(h);
    return ok;
}

int pos()
{
    node_t *n1 = get_str_raw();
    node_t *head1 = n1->head;
    node_t *n2 = get_str_raw();
    node_t *head2 = n2->head;
    int in1 = 0;
    int in2 = 0;
    int iter = 0;

    while (n1 != NULL)
    {
        if (n1->s[in1] == n2->s[in2])
        {
            if ((compare_str(n1, n2, in1)) == 0)
            {
                printf("%d", in1 + iter);
                delete_list(head1);
                delete_list(head2);
                return ok;
            }
        }

        in1++;

        if (in1 > 3)
        {
            in1 = 0;
            n1 = n1->next;
            iter += 4;
        }
    }

    delete_list(head1);
    delete_list(head2);
    return input_error;
}

