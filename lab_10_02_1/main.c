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
    int input_out = OK;
    int full_out = OK;

    while (input_out == OK && full_out == OK)
    {
        full_out = resize_items_array(&p, &array_size, ADD);
        input_out = fill_input(&p[i]);
        i++;
    }

    array_size--;

    if (array_size < 0 || input_out != ARTICLE_NOTHING)
    {
        for (int in = 0; in < array_size; in++)
        {
            free(p[in].article);
            free(p[in].name);
        }
        free(p);
        return INPUT_ERROR;
    }

    full_out = delete_lipstick(p, &array_size);
    input_out = get_key(key);
    full_out += sort_array(p, array_size, key);

    file_print_input(p, array_size);

    for (int in = 0; in < array_size; in++)
    {
        free(p[in].article);
        free(p[in].name);
    }
    free(p);

    if (input_out == OK && full_out == OK)
        return OK;
    else
    {
        return max(input_out, full_out);
    }
}