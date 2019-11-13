#include "stdio.h"
int main(){
    char c;
    int time,s=0;
    puts("input type C E T");
    c=getchar();
    puts("input time");
    scanf("%d",&time);
    switch (c)
    {
    case 'C':
    if(time<=3)s=time*5;
    else
    s+=(time-3)*10+(3*5);
        break;
    case 'E':
    if(time<=2)s=time*10;
    else 
    s+=(time-2)*15+(2*10);
        break;
    case 'T':
    if(time<=1)s=time*10;
    else
    s+=(time-1)*15+10;
        break;
    }
    printf("%d",s);
}