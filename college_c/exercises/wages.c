#include "stdio.h"

int main(){
    float s,t,x,p=1.8;
    puts("input distance and weight");
    scanf("%f%f",&s,&t);
    switch((int)s/250){
        case 0: x=s*t*p;break;
        case 1: x=s*t*p*(1-0.02);break;
        case 2: case 3:x=s*t*p*(1-0.05);
        case 4: case 5: case 6: case 7:
        x=s*t*p*(1-0.08);break;
        case 8: case 9: case 10: case 11: 
        x=s*t*p*(1-0.1);break;
        default :
        x=s*t*p*(1-0.15);
    }
    printf("%f",x);
   
}