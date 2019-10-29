#include "stdio.h"
void b(){
    int x,y,i=0,t;
    int a[5];
    while(i<5)
    scanf("%d",&a[i++]);

    for(x=0;x<5;x++){
        for(y=0;y<x;y++)
        if(a[y]<a[y+1])
        {t=a[y];a[y]=a[y+1];a[y+1]=t;}
    }
    for(x=0;x<5;x++)
    printf("%d\t",a[x]);
    
}

// void a(){
//     int x,y,a;
//     scanf("%d",&a);
//     for(y=0;y<a;y++){
// for(x=0;x<=y;x++){
//     putchar('$');
// }
// putchar('\n');
//     }
// }


int main(){
    // int *p=NULL;
    // int a=250;
    // p=&a;
    // printf("%p,%5d%5d",p,*p,a);

    // *p=234;
    // printf("\n%d,%d",*p,a);
    // return 0;
//a();
//b();

int i;
i=0;end:
if(i<10){
    printf("123\t");
    i++;
    goto end;
}

}

