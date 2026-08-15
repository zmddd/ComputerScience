#include <stdio.h>

int main()
{
    int lim = 0;
    char c;
    for (int i = 0;; ++i)
    {
        if (i >= lim - 1)
            break;
        if ((c = getchar()) == EOF)
            break;

        /* 循环体 */
    }
}
