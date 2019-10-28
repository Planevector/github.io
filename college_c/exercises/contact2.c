#include "stdio.h"
#include "math.h"

int main(){

float x,y,a,b;
puts("please input coordinate");
scanf("(%f,%f) (%f,%f)",&x,&y,&a,&b);

printf("midpoint:(%f,%f)\n",(x+y)/2,(a+b)/2);

printf("distance:%f",sqrt((x-a)*(x-a)+(y-b)*(y-b)));

return 0;
}

