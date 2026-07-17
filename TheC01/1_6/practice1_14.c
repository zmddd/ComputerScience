//题目意思是：
// 读入一段文本
// 把文本里的“单词”一个个分出来
// 统计每个单词的长度
// 再把“长度分布”画成直方图
// 也就是说，不是统计数字、空白符这些，而是统计“单词长度”。
#include <stdio.h>

int main() {
    int c, i, j;
    int len = 0;
    int max = 0;
    int counts[11] = {0};

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
            if (len > 0) {
                if (len > 10) {
                    len = 10;
                }
                counts[len]++;
                if (counts[len] > max) {
                    max = counts[len];
                }
                len = 0;
            }
        } else {
            len++;
        }
    }

    if (len > 0) {
        if (len > 10) {
            len = 10;
        }
        counts[len]++;
        if (counts[len] > max) {
            max = counts[len];
        }
    }

    for (i = max; i > 0; --i) {
        for (j = 1; j <= 10; ++j) {
            if (counts[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (j = 1; j <= 10; ++j) {
        printf("%d ", j);
    }
    printf("\n");

    return 0;
}
