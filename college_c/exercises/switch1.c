#include "stdio.h"

int main(){
    int year,month,day,i,count=0;
    scanf("%d%d%d",&year,&month,&day);
    if(month>0&&month<13&&day>0&&day<32){
        for(i=1;i<month;i++)
        switch(i){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            count+=31;break;
            case 2:
            if(year%4==0&&year%100!=0||year%400==0)
            count+=29;
            else
            count+=28;
            break;
            default :
            count+=30;
        }
    }
    else
    puts("error");
    printf("today is the %dth day of %dyear",count+day,year);
    return 0;
}