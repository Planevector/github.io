#include "stdio.h"

int main(){
    int x,y,d;
    scanf("%d,%d",&x,&y);
    if(y>=1&&y<=12){
    if(x%4==0&&x%100!=0||x%400==0)
    d=29;
    else
    d=28;
    if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)
    d=31;
    else
    if(y!=2)
    d=30; 
     printf("%d days in %dmonth %d",d,y,x);
    }
    else{
        puts("input error");
    }
}