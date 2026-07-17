#include <stdio.h>

int main(void)
{
    printf("%4s\n", "加个标题");
    float fahr;
    int celsius;
    int lower, upper, step;

    lower = -17;   /* 温度表的下限 */
    upper = 148;   /* 温度表的上限 */
    step = 20;     /* 步长 */

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (float)9.0 * celsius / (float)5.0 + (float)32;
        printf("%3d\t%.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}