#include "stdio.h"

#define N c-65

int main(){
    int x;
    char c,a;
    c=getchar();
if(c>='A'&&c<='Z')
    for(int i=0;i<=N;i++){
         for(int y=N;y>i;y--)putchar(' ');
         for(x=0,a='A';x<=i;x++)putchar(a++);
         for(x=0,--a;x<i;x++)putchar(--a);
        putchar('\n');
    }
    else
   puts("error please enter Capital");
}