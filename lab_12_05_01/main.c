#include "defines.h"
#include "user_interface.h"
#include "main_funcs.h"

int main()
{

    switch(get_command())
    {
        case (1):
            puts("OUT");
            out();
            break;
        case (2):
            puts("CAT");
            break;
        case (3):
            puts("SPS");
            break;
        case (4):
            puts("POS");
            break;
        default:
            return input_error;
    }

    return ok;
}