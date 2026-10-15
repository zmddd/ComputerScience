#include <stdio.h>

/*
编写函数 strindex(s, t)，它返回字符串 t 在 s 中最右边出现的位置。
如果 s 中不包含 t，则返回-1。
*/

int strindex(char s[], char t[])
{
    int i, j, k;
    int last = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (t[k] == '\0')
            last = i;
    }
    return last;
}

int main()
{

    char str[] = "abbbbbb";
    char test[] = "bb";
    int r = strindex(str,test);
    printf("%d\n",r);
    return 0;
}

