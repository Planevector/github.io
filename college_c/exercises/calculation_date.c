#include "stdio.h"
int d(int x){
    int y;
    if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)
    y=31;
    else
    y=30;
    return y;
}
int main(){
     int x,y;
     scanf("%d,%d",&x,&y);
     if(y>=1&&y<=12){
     if(x%4==0&&x%100!=0||x%400==0){
         if(y==2)
         printf("29 day");
         else
        printf("%d day",d(y));
     }else{
      if(y==2)
      printf("28 day");
      else
      printf("%d day",d(y));
     }
}
     else
     puts("input error");     
}