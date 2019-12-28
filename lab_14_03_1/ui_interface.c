//#include "ui_interface.h"
#include "defines.h"
#include "user_interface.h"
#include "main_funcs.h"
#include "resizing_items.h"
//#include "main.c"

/*void add_element(int *array_size, item_t **p, str_t a, str_t n, int c)
{
    resize_items_array(p, array_size, ADD);

    (&(*p)[*array_size - 1])->article = a;
    (&(*p)[*array_size - 1])->name = n;
    (&(*p)[*array_size - 1])->count = c;
}*/

/*int full_input(int *array_size, item_t **p)
{
    int i = 0;
    int input_out = ok;
    int full_out = ok;

    while (input_out == ok && full_out == ok)
    {
        full_out = resize_items_array(p, array_size, ADD);
        input_out = fill_input(&(*p)[i]);
        i++;
    }
    (*array_size)--;

    if (*array_size < 0 || input_out != article_nothing)
    {
        return input_error;
    }

    return ok;
    return ok;
}*/

