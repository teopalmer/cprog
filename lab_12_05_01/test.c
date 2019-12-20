#include "user_interface.h"
#include "main_funcs.h"
#include "test.h"
#include "stdarg.h"
#include "str_funcs.h"

int test_clean_str()
{
    str_t s = {'a', 'b', 'c', 'd'};
    str_t res = { 0 };
    clean_str(s);
    if (strcmp(s, res) != 0)
        return input_error;
    else
        return ok;
}

int main()
{
    return 0;
}
