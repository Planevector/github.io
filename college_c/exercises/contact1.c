#include "stdio.h"

int main(){

   int s,f,h;
   puts("please input second");
   scanf("%d",&s);
    h=s/3600;
    s%=3600;
    f=s/60;
    s%=60;
printf("%d:hour %d:branch %d:second\n",h,f,s);
    return 0;
}