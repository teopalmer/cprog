#include <stdio.h>
#include <string.h>
#define VALUE_ERROR 4
#define N 256
typedef char str_t[N];

int input(str_t s1, str_t s2)
{
    puts("Please enter two strings:");
    gets(s1);
    gets(s2);
    if (!s1 || !s2)
    {
        puts("The input is empty, YEET");
        return VALUE_ERROR;
    }
    return 0;
}

void output(str_t word, str_t tag)
{
    printf("%s %s", word, tag);
}

void split_words(str_t s1, str_t s2)
{
    str_t new_word;
    str_t prev_words;
    char *t;
    char * pch = strtok(s1," ,.-");
    
    while (pch != NULL)
    {
        strcpy(new_word, pch);
        t = strstr(s2, new_word);
        
        if (t != NULL)
        {
            //if (!strfind(new_word, prev_words))
            output(new_word, "yes\n");
            strcpy(prev_words, new_word);
            strcpy(prev_words, " ");
        }
        else
        {
            output(new_word, "no\n");
        }
        pch = strtok (NULL, " ,.-");
    }
}

int main()
{
    str_t s1, s2;
    //printf("^%d\n", strfind(s1, s2));
    if (!input(s1,s2))
    {
        puts("Result:");
        split_words(s1, s2);
        return 0;
    }
    return VALUE_ERROR;
}

