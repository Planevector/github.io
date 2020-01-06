#include "stdio.h"

void main(){
    int x,y,t;
    int a[15]={11,22,31,4,32,52,3,6,3,32,5,23,97,66,43};

    for(x=0;x<15-1;x++)
    for(y=0;y<15-x-1;y++)
    if(a[y]<a[y+1]){t=a[y];a[y]=a[y+1];a[y+1]=t;}

    for(int i=0;i<15;i++)
    printf("%5d",a[i]);
}