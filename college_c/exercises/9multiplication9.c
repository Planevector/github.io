#include "stdio.h"

int main(){
    for(int i=1;i<=9;i++){
        for(int x=1;x<=i;x++)
        printf("%d*%d=%d\t",x,i,i*x);
        putchar('\n');
    }
}