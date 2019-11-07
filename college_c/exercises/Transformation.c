#include "stdio.h"

int main(){
    char s;
    s=getchar();
    if(s>='a'&&s<='z')
    putchar(s-32);
    else
    if(s>='A'&&s<='Z')
    putchar(s+32);
    else
    puts("the character need not to be changed");
}