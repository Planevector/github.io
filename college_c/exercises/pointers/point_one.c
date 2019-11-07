#include "stdio.h"
#include "stdlib.h"

int main(){
    int *pnumber=NULL;
    int a=55,b=22;
    pnumber=&a;
    printf("a=%d\tp=%p\t*p=%d",a,pnumber,*pnumber);
    *pnumber=b;
    printf("\ta=%d\tp=%p\t",a,pnumber);
    pnumber=&b;
    b=a;
    printf("\tp=%p\tb=%d\t",pnumber,b);

return 0;
}