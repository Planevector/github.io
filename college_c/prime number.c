#include "stdio.h"
void main(){
 int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int x,i,count;
    for(i=0;i<20;i++){
        for(x=2;x<a[i];x++){
            if(a[i]%x==0)break;
        }
        if(x==a[i]){
            count++;
            printf("%5d",x);
        }
    }
    printf("\ncount=%d\n",count);

}