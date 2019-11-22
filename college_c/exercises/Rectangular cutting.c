#include "stdio.h"

int main(){
    int sum=0,x,y,t ;
    puts("input height wdith:");
    scanf("%d%d",&x,&y);
    while(x>0){
        sum+=y/x;
        t=x;
        x=y%x;
        y=t;
         printf("%drectangles\tx=%d\ty=%d\n",sum,x,y);
        
    }

    printf("\n%drectangles",sum);
}