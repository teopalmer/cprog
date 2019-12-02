#include "defines.h"
#include "user_interface.h"

int main() {

    switch(get_command())
    {
        case (1):
            puts("OUT");
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


    return 0;
}