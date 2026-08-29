/*
练习1-20|编写程序detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。假设制表符终止位的位置是固定的，比如每隔n列就会出现个制表符终止位。n应该作为变量还是符号常量呢?
*/
#include <stdio.h>
#define TAB_STOP 8

void detab(void) {   // �ĳ� void ������
    int c, pos = 0;
    printf("=== �������������������ı���Ctrl+Z �س�������===\n");
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TAB_STOP - (pos % TAB_STOP);
            for (int i = 0; i < spaces; ++i) {
                putchar(' ');
                ++pos;
            }
        } else {
            putchar(c);
            ++pos;
            if (c == '\n') pos = 0;
        }
    }
}

int main(void) {
    detab();
    return 0;
}
