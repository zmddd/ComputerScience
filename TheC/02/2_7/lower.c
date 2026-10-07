/**
 * 标准库tolower函数的实现
 */
#include <stdio.h>

int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); // 将大写字母转换为小写字母
    }
    return c; // 非大写字母保持不变
}
int main(){
    int c = lower(65);
    printf("%c\n", c); // 输出小写字母 'a'
    return 0;
}
