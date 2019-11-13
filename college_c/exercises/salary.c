#include "stdio.h"
float calculation(float x){
    float s;
    if(x<2000) s=0;
    else
    if(x<2500) s=(x-2000)*0.05;
    else
    if(x<4000) s=(500*0.05)+(x-2500)*0.1;
    else
    s=(500*0.05)+(1500*0.1)+x-4000*1.5;
    return s;
}
int main(){
   int type,money;
   scanf("%d",&type);
   switch (type)
   {
   case 1:
   puts("input  piece wages Hourly wage hour");
    float x,y;{
    scanf("%f%f",&x,&y);
    float s=x*y;
    printf("%f",s*30-calculation(s));
       break;}
    case 2:{
    puts("input Quantity wage Quantity wage");
    float x,y;
    scanf("%f%f",&x,&y);
    float s=x*y;
    printf("%f",s*30-calculation(s));
    break;
    }
    case 3:{
    puts("input wage");
    float x;
    scanf("%f",&x);
    printf("%f",x-calculation(x));
    break;}
   }
}                                                                                                                                                                                                                                                                                                                                                                                                       