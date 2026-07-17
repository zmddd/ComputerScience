#include <stdio.h>
//键盘输入字符 ctrl + z 回车
int main(){
    double nc;
    for (nc = 0;getchar() != EOF; ++nc) ;
    printf("%6.0f\n",nc);
}