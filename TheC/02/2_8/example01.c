#include <stdio.h>
/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int main(){
    char s[] = "hello world";
    int c = 'o';
    squeeze(s, c);
    printf("%s\n", s);
    getchar(); // 等待用户按回车再关闭
    return 0;
}