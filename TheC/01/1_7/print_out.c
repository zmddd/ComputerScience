// 使用递归函数逐步打印一个多位整数
#include <stdio.h>

void printDigit(int digit) {
    putchar('0' + digit);
}

void printOut( unsigned int N){
    if(N >= 10)
        printOut(N / 10);
    printDigit(N % 10);
}

int main(){
    printOut(12);
    putchar('\n');
    return 0;
}
