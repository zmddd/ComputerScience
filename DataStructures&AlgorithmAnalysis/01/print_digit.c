// 题目要求只用 PrintDigit 输出数字字符
// ◦ 所以不能直接用 printf 把整个实数格式化输出
// ◦ 只能把每一位数字单独打印出来
// 2. 先处理符号
// ◦ 如果实数为负数，先输出 -
// ◦ 再把数值取绝对值继续处理
// 3. 分成整数部分和小数部分
// ◦ 整数部分用整型保存
// ◦ 小数部分用原数减去整数部分得到
// 4. 整数部分递归输出
// ◦ 先把整数部分不断除以 10，直到最左边的位
// ◦ 然后按返回顺序逐位输出
// ◦ 这个就是最典型的“递归输出整数每一位”的教材套路
// 5. 小数部分逐位输出
// ◦ 小数部分乘 10，取整得到第一位小数
// ◦ 减去这个整数部分，得到剩下的小数
// ◦ 反复做若干次，输出固定精度的小数位
// ◦ 教材通常会规定输出几位小数，比如 6 位或题目要求的位数
// 6. 中间加小数点
// ◦ 整数输出完后，输出一个 . 再输出小数位

#include <stdio.h>

void PrintDigit(int digit)
{
    putchar('0' + digit);
}

void PrintInt(int n)
{
    printf("%d\n",n);
    if (n >= 10)
        PrintInt(n / 10);
    PrintDigit(n % 10);
}

void PrintReal(double x)
{
    int intPart;
    double fracPart;
    int i;

    if (x < 0)
    {
        putchar('-');
        x = -x;
    }

    intPart = (int)x;
    fracPart = x - intPart;

    PrintInt(intPart);
    putchar('.');

    for (i = 0; i < 6; i++)
    {
        fracPart *= 10;
        PrintDigit((int)fracPart);
        fracPart -= (int)fracPart;
    }
}

int main(void)
{
    PrintReal(-12.3456);
    return 0;
}
