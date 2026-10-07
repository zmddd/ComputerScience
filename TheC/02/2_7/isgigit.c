/**
 * 标准库isdigit函数的实现
 * <ctype.h>
 */

#include <stdio.h>

int isdigit(int c) {
    return c >= '0' && c <= '9';
}

int main(){
    int c = getchar();
    int res = isdigit(c);
    printf("%d\n", res); // 输出 1
    return 0;
}
