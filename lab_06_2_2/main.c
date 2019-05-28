#include <stdio.h>
#include <string.h>
#define VALUE_ERROR 4
#define N 256
typedef char str_t[N];

int input(str_t s1, str_t s2)
{
    puts("Please enter two strings:");
    fgets(s1, N, stdin);
    fgets(s2, N, stdin);
    if (s1[0] == '\0' || s2[0] == '\0')
    {
        puts("The input is empty, YEET");
        return VALUE_ERROR;
    }
    return 0;
}

int strcheck(str_t s, str_t m)
{
    if (strstr(m, s))
        return 0;
    return 1;
}

void output(str_t word, str_t tag)
{
    str_t wordn = "";
    if (word[strlen(word) - 1] == '\n')
        for (int i = 0; i < strlen(word) - 1; i++)
            wordn[i] = word[i];
    else
        strcpy(wordn, word);
    printf("%s %s", wordn, tag);
}

void split_words(str_t s1, str_t s2)
{
    str_t new_word;
    str_t prev_words = "0 ";
    char *t;
    char *pch = strtok(s1, " ,.-");
    while (pch != NULL)
    {
        strcpy(new_word, pch);
        t = strstr(s2, new_word);
        
        if (t != NULL)
        {
            if (strstr(prev_words, new_word)==NULL)
            {
                //printf("%s\n", (strstr(new_word, prev_words)));
                output(new_word, "yes");
            }
            //printf("^ %s\n", (strstr(new_word, prev_words)));
            strcat(prev_words, new_word);
            strcat(prev_words, " ");
            //printf("^1 %s / %s\n", new_word, prev_words);
        }
        else
        {
            if (strstr(prev_words, new_word)==NULL)
                output(new_word, "no");
            strcat(prev_words, new_word);
            strcat(prev_words, " ");
        }
        pch = strtok(NULL, " ,.-");
        if (pch != NULL)
            puts("");
    }
}

int main()
{
    str_t s1, s2;
    if (!input(s1, s2))
    {
        puts("Result:");
        split_words(s1, s2);
        return 0;
    }
    return VALUE_ERROR;
}

