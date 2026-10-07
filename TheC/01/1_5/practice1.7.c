#include <stdio.h>

//EOF 是定义在 <stdio.h> 里的一个宏，它本身是一个 int 类型的负整数常量，通常为 -1
int main(){
    int c;
    c =  EOF;
    printf("%d\n",c);
}
