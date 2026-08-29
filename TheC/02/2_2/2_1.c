#include <stdio.h>
#include <limits.h>

#if 0
int main(void) {
    // 计算 char 类型的位数，通常为 8，但这里使用 sizeof(char) 以保持通用性
    int N = sizeof(char) * 8;

    // unsigned char 的最大值：N 位全为 1，即 2^N - 1
    //1u << N 的含义就是把 1 向左移 N 位，等价于 2^N
    //signed char c = “128”
    unsigned int uchar_max = (1u << N) - 1u;

    // signed char 的范围假设采用二补码表示：
    // 最大值为 2^(N-1) - 1，最小值为 -2^(N-1)
    int schar_max = (1 << (N - 1)) - 1;
    int schar_min = - (1 << (N - 1));

    printf("char 位数 = %d\n", N);
    printf("unsigned char 取值范围: %u .. %u\n", 0u, uchar_max);
    printf("signed char 取值范围: %d .. %d\n", schar_min, schar_max);

    // 验证结果与 limits.h 中定义的常量是否一致
    printf("limits.h: UCHAR_MAX = %u, SCHAR_MIN = %d, SCHAR_MAX = %d\n",
           (unsigned)UCHAR_MAX, SCHAR_MIN, SCHAR_MAX);

    return 0;
}
#endif

int main(void) {
    // 计算 int 类型的位数
    int N = sizeof(int) * 8;

    // 计算 int 的正数范围：2^(N-1) - 1
    unsigned long long one = 1ull;
    unsigned long long positive_limit = (one << (N - 1)) - 1ull;
    int int_max = (int)positive_limit;

    // 计算 int 的最小值：-2^(N-1)
    long long negative_limit = - (long long)(one << (N - 1));
    int int_min = (int)negative_limit;

    printf("int 位数 = %d\n", N);
    printf("int 取值范围: %d .. %d\n", int_min, int_max);
    printf("limits.h: INT_MIN = %d, INT_MAX = %d\n", INT_MIN, INT_MAX);

    return 0;
}

