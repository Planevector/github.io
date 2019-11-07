#include "stdio.h"

int main(){
float h,w,s;
puts("please input Height(M) and weight(KG)");
scanf("%f%f",&h,&w);
s=w/(h*h);
if(s<18.5)
puts("偏瘦");   
else
    if(s<23.9)
    puts("正常");
else
if(s<27.9)
puts("超重");
    else
    puts("肥胖");
}