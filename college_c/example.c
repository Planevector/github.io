#include "stdio.h"

void main(){
    int sum=0,swp=0;
    for(int i=1;i<10;i++){
        swp=swp*10+i;
        printf("%d->",swp);
        sum+=swp;
    }
    printf("\nsum=%d",swp);
}