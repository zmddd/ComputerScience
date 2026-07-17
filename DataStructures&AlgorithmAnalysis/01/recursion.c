#include <stdio.h>


//C = 5 (F - 32) /9
//F = 2F(x-1) + X^2
int F(int x){
    if(x==0){
        return 0;
    }else {
        return 2*F(x-1) + x*x;
    }         
}
int main(){
    printf("%d",F(10));
}