#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 100000

int main(){
    int *px=(int *)malloc(N*sizeof(int));
    if(!px){
        printf("error");
        return 0;
    }

    srand((unsigned)time(NULL));
    for(int x=0;x<N;x++)
    px[x]=rand()%N;

    for(int x=0;x<N;x++)
    for(int y=0,t;y<=x;y++)
    if(px[y]>px[y+1])
    {t=px[y];px[y]=px[y+1];px[y+1]=t;}

    for(long x=0;x<N;x++)
    printf("[%d]\t",px[x]);


}
