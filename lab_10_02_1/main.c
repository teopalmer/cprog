#include "defines.h"
#include "user_interface.h"
#include "resizing_items.h"
#include "main_funcs.h"

int main()
{
    item_t *p = NULL;
    str_t key;
    int array_size = 0;

    if (full_input(&array_size, &p) != ok)
    {
        clear(&p, array_size);
        return input_error;
    }

    if (delete_lipstick(p, &array_size) != ok || array_size == 0)
    {
        clear(&p, array_size);
        return memory_error;
    }

    if (get_key(key) != ok)
    {
        clear(&p, array_size);
        return input_error;
    }

    if (sort_array(p, array_size, key) != ok)
    {
        clear(&p, array_size);
        return memory_error;
    }

    file_print_input(p, array_size);

    clear(&p, array_size);

    if (array_size > 0)
        return ok;
}
