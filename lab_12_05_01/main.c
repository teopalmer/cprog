#include "defines.h"
#include "user_interface.h"
#include "main_funcs.h"

int main()
{
    switch (get_command())
    {
        case (1):
            return out();
        case (2):
            return cat();
        case (3):
            return sps();
        case (4):
            return pos();
        default:
            return input_error;
    }
}