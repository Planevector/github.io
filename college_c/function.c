#include "time.h"
#include "stdio.h"
#include "stdlib.h"
//user realloc realize infinite input
int main(){
    int x,y=0;
    int *px=malloc(5*sizeof(int));
    for(int i=0;i<8;i++){
        scanf("%d",&px[i]);
        if(y>=10)
        px=(int *)realloc(px,++y*sizeof(int));
        else
        y++;
    }

    for(int i=0;i<8;i++)
    printf("%d\t",px[i]);


    // srand((unsigned)time(NULL));
    // for(int i=0;i<10;i++)
    // printf("%d\t",px[i]=rand()%100);


}