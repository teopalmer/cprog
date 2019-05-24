#include <stdio.h>
#include <string.h>

char* my_strpbrk(char a[], char b[])
{
    char* ans = NULL;
    int len_b = strlen(b);
    int len_a = strlen(a);
    for (int i = 0; i < len_b; ++i)
    {
        int cou = 0;
        while (cou < len_a && a[cou] != b[i])
        {
            ++cou;
        }
        if (cou < len_a && (!ans || a + cou < ans))
        {
            ans = a + cou;
        }
    }
    return ans;
}

size_t my_strspn(char a[], char b[])
{
    size_t ans = 0;
    int len_b = strlen(b);
    int len_a = strlen(a);
    int flag = 1;
    int cou = -1;
    while (cou < len_a - 1 && flag)
    {
        ++cou;
        int cou2 = 0;
        while (cou2 < len_b && a[cou] != b[cou2])
        {
            ++cou2;
        }
        if (cou2 < len_b)
        {
            ++ans;
        }
        else
        {
            flag = 0;
        }
    }
    return ans;
}

size_t my_strcspn(char a[], char b[])
{
    int len_b = strlen(b);
    int len_a = strlen(a);
    size_t ans = len_a;
    for (int i = 0; i < len_b; ++i)
    {
        int cou = 0;
        while (cou < len_a && a[cou] != b[i])
        {
            ++cou;
        }
        if (cou < ans)
        {
            ans = cou;
        }
    }
    return ans;
}

char* my_strchr(char a[], int sym)
{
    int len_a = strlen(a);
    char* ans = NULL;
    int cou = 0;
    while (cou < len_a && a[cou] != sym)
    {
        ++cou;
    }
    if (cou < len_a && (!ans || cou < ans - a))
    {
        ans = a + cou;
    }
    return ans;
}

char* my_strrchr(char a[], int sym)
{
    int len_a = strlen(a);
    char* ans = NULL;
    int cou = len_a - 1;
    while (cou >= 0 && a[cou] != sym)
    {
        --cou;
    }
    if (cou >= 0 && (!ans || cou > ans - a))
    {
        ans = a + cou;
    }
    return ans;
}


int main()
{
    char a[] = "bbbbbbbCcc";
    char b[] = "acc";
    char c = 'c';
    if (my_strpbrk(a, b) != strpbrk(a, b))
    {
        printf("Error!");
        return -1;
    }
    if (my_strspn(a, b) != strspn(a, b))
    {
        printf("Error!");
        return -1;
    }
    if (my_strcspn(a, b) != strcspn(a, b))
    {
        printf("Error!");
        return -1;
    }
    if (my_strchr(a, c) != strchr(a, c))
    {
        printf("Error!");
        return -1;
    }
    if (my_strrchr(a, c) != strrchr(a, c))
    {
        printf("Error!");
        return -1;
    }
    char a1[] = "bbabbbababCcc";
    char b1[] = "acbc";
    char c1 = 'd';
    if (my_strpbrk(a1, b1) != strpbrk(a1, b1))
    {
        printf("Error!");
        return -1;
    }
    if (my_strspn(a1, b1) != strspn(a1, b1))
    {
        printf("Error!");
        return -1;
    }
    if (my_strcspn(a1, b1) != strcspn(a1, b1))
    {
        printf("Error!");
        return -1;
    }
    if (my_strchr(a1, c1) != strchr(a1, c1))
    {
        printf("Error!");
        return -1;
    }
    if (my_strrchr(a1, c1) != strrchr(a1, c1))
    {
        printf("Error!");
        return -1;
    }
    printf("OK!");
    return 0;
}
