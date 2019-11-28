#include "defines.h"
#include "str_funcs.h"

int my_strlen(str_t const s)
{
    int i = 0;

    while (s[i])
    {
        i++;
    }
    return i;
}

int convert(char *s, int n)
{
    unsigned int x = 0;
    for (char *p = s; *p; p++)
    {
        x *= 10;
        x += (int)(*p - '0');
        x %= n;
    }
    return x;
}

void convert_to_str(char *s, unsigned int n)
{
    while (n > 0)
    {
        *s = (n % 10);
        n /= 10;
        s++;
    }
    //s[i] = '\0';
}

void reverse(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *from_deci(str_t res, int inum)
{
    int index = 0;
    while (inum > 0)
    {
        res[index++] = (inum % 8) + '0';
        inum /= 8;
    }
    res[index] = '\0';
    reverse(res);
    return res;
}

char *hd_to_str(str_t res, int inum)
{
    int index = 0;
    int flag = 0;
    if (inum < 0)
        flag = 1;
    while (abs(inum) > 0)
    {
        res[index++] = abs(inum % 10) + '0';
        inum /= 10;
    }
    if (flag == 1)
        res[index++] = '-';

    res[index] = '\0';
    reverse(res);
    return res;
}

void merge_str(char *a, char *b)
{
    while (*a)
        a++;

    while (*b)
    {
        *a = *b;
        b++;
        a++;
    }
    *a = '\0';
}

void merge_char(char *a, char b)
{
    while (*a)
        a++;
    *a = b;
    a++;
    *a = '\0';
}
