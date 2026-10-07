/*
编写程序entab，将空格串替换为最少数量的制表符和空格，但要保持单词;
练习1-21之间的间隔不变。假设制表符终止位的位置与练习1-20的detab程序的情况相同。当使用一个制表符或者一个空格都可以到达下一个制表符终止位时，选用哪一种替换字符比较好?
*/
#include <stdio.h>
#define TAB_STOP 4

int entab(void) {
    int c, pos = 0, space_count = 0;
    // 提示信息可以放到 stderr 或临时去掉，避免干扰输出
    fprintf(stderr, "=== 输入文本，Ctrl+Z 回车结束 ===\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++space_count;       // 只计数，不动 pos
        } else {
            // 先处理累计的空格
            while (space_count > 0) {
                int to_next = TAB_STOP - (pos % TAB_STOP);
                if (space_count >= to_next) {
                    putchar('\t');
                    pos += to_next;
                    space_count -= to_next;
                } else {
                    putchar(' ');
                    ++pos;
                    --space_count;
                }
            }
            // 处理非空格字符
            putchar(c);
            if (c == '\n')
                pos = 0;
            else
                ++pos;
        }
    }
    // 文件结束时，可能还有未输出的空格
    while (space_count > 0) {
        int to_next = TAB_STOP - (pos % TAB_STOP);
        if (space_count >= to_next) {
            putchar('\t');
            pos += to_next;
            space_count -= to_next;
        } else {
            putchar(' ');
            ++pos;
            --space_count;
        }
    }
    return 0;
}

int main(void) {
    entab();
    return 0;
}