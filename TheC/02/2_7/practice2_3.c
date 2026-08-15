/**
 * 编写函数htoi(s)，把由十六进制数字组成的字符串(包含可选的前缀0x
 * 或0x)转换为与之等价的整型值。字符串中允许包含的数字包括:0~9、a~f以及A~F。
 */
#include <stdio.h>

int htoi(const char *s) {
    int result = 0;
    int i = 0;

    // 跳过前缀 "0x" 或 "0X"
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    for (; s[i] != '\0'; ++i) {
        char c = s[i];
        int value;

        if (c >= '0' && c <= '9') {
            value = c - '0';
        //原因：十六进制字符 'a'..'f' 表示的数值是 10..15。表达式 c - 'a' 把字符转换为 0..5，
        //后再加 10 得到 10..15，所以 c - 'a' + 10 正好把 'a' 映射到 10，'f' 映射到 15。
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else {
            // 遇到非十六进制字符，停止转换
            break;
        }

        result = result * 16 + value;
    }

    return result;
}
int main()
{
    const char *hex_str = "0x1A3F";
    int decimal_value = htoi(hex_str);
    printf("Hexadecimal: %s, Decimal: %d\n", hex_str, decimal_value);
    return 0;
}