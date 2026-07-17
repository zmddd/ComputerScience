#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 交换两个整数 */
static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * 题目考察点：
 * 1. 选择问题：找到第 k 小的元素。
 * 2. 令 k = N / 2，实际上是在求中位数附近的元素。
 * 3. 通过测量不同 N 值下的运行时间，观察算法复杂度趋势。
 *
 * 解题思路：
 * - 用快速选择算法，而不是先排序再取值。
 * - 这样可以在平均情况下更快地找到第 k 小的元素。
 * - 通过多组不同大小的输入，统计运行时间，形成一张表格。
 */
static int quickselect(int *a, int left, int right, int k) {
    while (left <= right) {
        /* 随机选一个基准值，减少最坏情况 */
        int pivot = a[left + rand() % (right - left + 1)];
        int i = left;
        int j = right;

        /* 把数组分成小于等于 pivot 和大于 pivot 的两部分 */
        while (i <= j) {
            while (a[i] < pivot) {
                ++i;
            }
            while (a[j] > pivot) {
                --j;
            }
            if (i <= j) {
                swap(&a[i], &a[j]);
                ++i;
                --j;
            }
        }

        /* 根据 k 的位置继续在左半边或右半边查找 */
        if (j >= k) {
            right = j;
        } else if (i <= k) {
            left = i;
        } else {
            break;
        }
    }

    return a[k];
}

int main(void) {
    /* 设定不同的 N 值，用来观察运行时间随数据规模增长的变化 */
    const int sizes[] = {10000, 20000, 50000, 100000, 200000, 500000};
    const int count = sizeof(sizes) / sizeof(sizes[0]);
    int s;

    /* 初始化随机种子，保证每次运行的数据不同 */
    srand((unsigned)time(NULL));

    printf("N\tTime(ms)\tSelected(k=N/2)\n");
    printf("----------------------------------------\n");

    for (s = 0; s < count; ++s) {
        int n = sizes[s];
        int k = n / 2;                  /* 取中位数位置 */
        int *a = (int *)malloc(sizeof(int) * n);
        clock_t start;
        double elapsed = 0.0;
        int result;
        int trial;

        if (a == NULL) {
            fprintf(stderr, "Out of memory for N = %d\n", n);
            return 1;
        }

        /* 连跑 5 次，减少偶然误差 */
        for (trial = 0; trial < 5; ++trial) {
            int j;
            for (j = 0; j < n; ++j) {
                a[j] = rand() % 100000;   /* 生成随机整数 */
            }

            start = clock();
            result = quickselect(a, 0, n - 1, k);
            elapsed += (double)(clock() - start) / CLOCKS_PER_SEC * 1000.0;
        }

        elapsed /= 5.0;
        printf("%d\t%.3f\t%d\n", n, elapsed, result);
        free(a);
    }

    return 0;
}
