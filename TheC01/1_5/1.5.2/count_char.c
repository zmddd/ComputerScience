#include <stdio.h>
//键盘输入字符 ctrl + z 回车
int main(){
    long nc = 0;
    while (getchar() != EOF) 
        ++nc;
    printf("%1d\n",nc);
}