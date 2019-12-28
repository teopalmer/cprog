#include "user_interface.h"

int get_command()
{
    char s[256];
    int ch = scanf("%s", s);
    if (ch != 1)
        return 0;
    if (!strcmp("out", s))
        return 1;
    if (!strcmp("cat", s))
        return 2;
    if (!strcmp("sps", s))
        return 3;
    if (!strcmp("pos", s))
        return 4;
    return 0;
}
