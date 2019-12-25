#include "main_funcs.h"
#include "list_funcs.h"
#include "str_funcs.h"
#include "string.h"

int out()
{
    while (fgetc(stdin) != '\n');
    node_t *n = get_str_raw();

    if (n == NULL)
    {
        delete_list(n);
        return input_error;
    }


    node_t *head = n->head;

    while (n != NULL)
    {
        print_str(n->s);
        n = n->next;
    }

    if (head != NULL)
        delete_list(head);

    return ok;
}

int cat()
{
    while (fgetc(stdin) != '\n');
    node_t *n1 = get_str_raw();

    if (n1 == NULL)
    {
        delete_list(n1);
        return input_error;
    }

    node_t *head1 = n1->head;
    node_t *n2 = get_str_raw();

    if (n2 == NULL)
        return input_error;

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

    if (head1 != NULL)
        delete_list(head1);

    if (head2 != NULL)
        delete_list(head2);
    return ok;
}

int sps()
{
    while (fgetc(stdin) != '\n');
    node_t *n = get_str_raw();

    if (n == NULL)
    {
        return input_error;
    }


    node_t *head = n->head;
    int flag = 0;

    while (n != NULL)
    {
        flag = print_str_sps(n->s, flag);
        n = n->next;
    }

    if (head != NULL)
    {
        delete_list(head);
    }

    return ok;
}

int pos()
{
    while (fgetc(stdin) != '\n');
    node_t *n1 = get_str_raw();

    if (n1 == NULL)
    {
        delete_list(n1);
        return input_error;
    }

    node_t *head = n1->head;
    node_t *n2 = get_str_raw();

    if (n2 == NULL)
    {
        delete_list(n1);
        delete_list(n2);
        return input_error;
    }

    node_t *head2 = n2->head;

    int in1 = 0;
    int iter = 0;

    while (n1 != NULL)
    {
        if (n1->s[in1] == n2->s[0])
        {
            if ((compare_str(n1, n2, in1)) == 0)
            {
                printf("%d", in1 + iter);
                delete_list(head);
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

    if (head != NULL)
    {
        delete_list(head);
        delete_list(head2);
    }

    printf("-1");
    return ok;
}

