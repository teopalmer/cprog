#include "snprintf.h"
#include "defines.h"
#include "str_funcs.h"

int my_snprintf(char *str, size_t size, char *format, ...)
{
    str_t res_str = "";
    int i = 0;
    int buf = 0;
    int qlen = 0;
    va_list(args);
    va_start(args, format);

    if (str == NULL && size != 0)
        return -1;

    while (format[i])
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
                    if (format[i])
                    {
                        merge_char(res_str, '%');
                        i ++;
                    }
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
                    str_t so;
                    from_deci(so, o);
                    len = my_strlen(so);
                    merge_str(res_str, so);
                    buf += len;
                    i ++;
                    break;
                case ('h'):
                    if (format[i + 2] == 'd')
                    {
                        int dx = va_arg(args, int);
                        if (dx < SHORTMIN || dx > SHORTMAX)
                        {
                            puts("*");
                            qlen = 2;
                            strcpy(str, "-1");
                            return size_error;
                        }
                        str_t sd;
                        d = dx;
                        hd_to_str(sd, d);
                        len = my_strlen(sd);
                        merge_str(res_str, sd);
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

    qlen = my_strlen(res_str);

    if (size == 0 && str != NULL)
    {
        str[0] = '\0';
        return (int)(qlen);
    }

    if (str)
    {
        my_strcpy(str, res_str, (int)size);
    }

    va_end(args);
    return qlen;
}
