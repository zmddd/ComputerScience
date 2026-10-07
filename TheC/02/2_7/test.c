#include <stdio.h>

int main(){
    char c = getchar();
    int d = c>='0' && c<='9';
    printf("%d\n", d);
}
