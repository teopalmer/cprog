#include "defines.h"
#include "user_interface.h"

int main()
{
    node_t *n = NULL;
    node_t *head = get_input(n);
    print_list(head);
}
