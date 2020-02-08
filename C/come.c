#include "stdio.h"

void main(){
    printf("0=%d a=%d A=%d\n",'0','a','A');
    printf("023=%d",0223);

    char ch=getchar();
    switch (ch)
    {
    case 'a' :printf("a=%c",ch);
    default: printf("end!");
    case 'b' :printf("b=%c",ch);
    case 'c' :printf("c=%c",ch);
    }
}