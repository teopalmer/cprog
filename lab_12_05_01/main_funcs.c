#include "main_funcs.h"
#include "list_funcs.h"
#include "str_funcs.h"
#include "string.h"

int out()
{
    node_t *n = get_str_raw();
    node_t *head = n->head;

    if (n == NULL)
        return input_error;


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
    node_t *n2 = get_str_raw();

    if (!n1 || !n2)
        return memory_error;

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
    delete_list(n1->head);
    delete_list(n2->head);
    return ok;
}

int sps()
{
    node_t *n = get_str_sps();

    if (n == NULL)
        return memory_error;

    while (n != NULL)
    {
        print_str(n->s);
        n = n->next;
    }
    delete_list(n->head);
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

    if (n1 == NULL || n2 == NULL)
        return input_error;

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