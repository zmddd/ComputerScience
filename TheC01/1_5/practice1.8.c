#include <stdio.h>
int main(void)
{
    int c;
    int in_space = 0;

    while ((c = getchar()) != EOF) {
        //也就是当遇到空格时，只有 in_space == 0（前一个字符不是空格）才输出一个空格，后续连续空格就不再输出
        if (c == ' ') {
            if (!in_space) {
                putchar(' ');
                in_space = 1;
            }
        } else {
            putchar(c);
            in_space = 0;
        }
    }

    return 0;
}