#include "snprintf.h"
#include "defines.h"
#include "str_funcs.h"

int resize_p(char *p, int n)
{
    char *pnew = realloc(p, (size_t)n);

    if (pnew == NULL)
        return memory_error;

    p = pnew;
    return ok;
}

int my_snprintf(char *str, size_t size, char *format, ...)
{
    str_t res_str = "";
    int i = 0;
    int buf = 0;
    va_list(args);
    va_start(args, format);

    if (str == NULL && size != 0)
        return -1;

    if (size == 0)
        return ok;

    while (format[i] && size + buf > i + 1)
    {
        int len = 0;
        char *s = NULL;
        unsigned int o = 0;
        short int d = 0;
        if (format[i] != '%')
        {
            merge_char(res_str, format[i]);
        }
        else
        {
            switch (format[i + 1])
            {
                case ('%'):
                    merge_str(res_str, "%");
                    i ++;
                    break;
                case ('s'):
                    s = va_arg(args, char*);
                    len = my_strlen(s);
                    merge_str(res_str, s);
                    buf += len;
                    i ++;
                    break;
                case ('o'):
                    o = va_arg(args, unsigned int);
                    str_t s;
                    from_deci(s, o);
                    len = my_strlen(s);
                    merge_str(res_str, s);
                    buf += len;
                    i ++;
                    break;
                case ('h'):
                    if (format[i + 2] == 'd')
                    {
                        d = (short) va_arg(args, int);
                        str_t s;
                        hd_to_str(s, d);
                        int len = my_strlen(s);
                        merge_str(res_str, s);
                        buf += len;
                        i += 2;
                    }
                    break;
                default:
                    break;
            }
        }
        i++;
    }

    strcpy(str, res_str);
    str[size - 1] = '\0';
    va_end(args);
    return ok;
}
