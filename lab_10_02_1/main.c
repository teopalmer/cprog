#include "defines.h"
#include "user_interface.h"
#include "resizing_items.h"
#include "main_funcs.h"

int main()
{
    item_t *p = NULL;
    str_t key;
    int array_size = 0;
    int i = 0;
    int err_flag = ok;

    if (full_input(&array_size, &p) != ok)
        return input_error;

    err_flag += delete_lipstick(p, &array_size);
    err_flag += get_key(key);
    err_flag += sort_array(p, array_size, key);

    file_print_input(p, array_size);

    for (int in = 0; in < array_size; in++)
    {
        free(p[in].article);
        free(p[in].name);
    }
    free(p);

    if (err_flag == ok && array_size > 0)
        return ok;
    else
    {
        puts("NO");
        return memory_error;
    }
}
