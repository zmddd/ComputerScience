/**
 * 编写一个函数 setbits(x, p, n, y)，该函数返回对 x 执行下列操作后
 * 的结果值：将 x 中从第 p 位开始的 n 个（二进制）位设置为 y 中最右边 n 位的值，x 的其余
 * 各位保持不变。
 * 步骤：
 * 1. 取出 y 的最右 n 位：mask = (1u << n) - 1； y_bits = y & mask。
 * 2. 构造清零掩码（在 x 的目标区间置 0）：clear_mask = ~(mask << (p + 1 - n))。
 * 3. 将 x 的对应位清零：x_cleared = x & clear_mask。
 * 4. 将 y_bits 左移到目标位置并与 x_cleared 或运算：result = x_cleared | (y_bits << (p + 1 - n))。
 */
#include <stdio.h>

int setbits(x, p, n, y){
    //1取出 y 的最右 n 位：
    int mask = (1u << n) - 1;
    int y_bits = y & mask;

    //2构造清零掩码（在 x 的目标区间置 0）
    int clear_mask = ~(mask << (p + 1 - n));

    //3 将 x 的对应位清零
    int x_cleared = x & clear_mask;

    //将 y_bits 左移到目标位置并与 x_cleared 或运算
    int result = x_cleared | (y_bits << (p + 1 - n));
    return result;
}
