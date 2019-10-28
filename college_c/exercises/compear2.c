#include "stdio.h"

int main(){
    int a,b,c,t;
    scanf("%d%d%d",&a,&b,&c);
    if(b>c){t=b;b=c;c=t;}
    if(a>b){t=a;a=b;b=t;}
    if(b>c){t=b;b=c;c=t;}
    printf("%5d%5d%5d",a,b,c);
    return 0;

}

void b(){
    int x,y,i=0,t;
    int a[5];
    while(i<5)
    scanf("%d",&a[i++]);

    for(x=0;x<5;x++){
        for(y=0;y<x;y++)
        if(a[y]<a[y+1])
        {t=a[y];a[y]=a[y+1];a[y+1]=t;}
    }
    for(x=0;x<5;x++)
    printf("%d\t",a[x]);
    
}