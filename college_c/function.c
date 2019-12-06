#include "time.h"
#include "stdio.h"
#include "stdlib.h"
//user realloc realize infinite input
int main(){
    int x,y=0,i;
    int *px=(int *)malloc(5*sizeof(int));
    for(i=0;i<5;i++)
    scanf("%d",&px[i]);
    px=(int *)realloc(px,5*sizeof(int));
    for(;i<10;i++)
    scanf("%d",&px[i]);

    for(int x=0;x<10;x++)
    printf("%d\t",px[x]);




    // srand((unsigned)time(NULL));
    // for(int i=0;i<10;i++)
    // printf("%d\t",px[i]=rand()%100);


}



// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
// int i;
// int *pn=(int *)malloc(5*sizeof(int));
// printf("%p\n",pn);
// for(i=0;i<5;i++)
// scanf("%d",&pn[i]);
// pn=(int *)realloc(pn,10*sizeof(int));
// printf("%p\n",pn);
// for(i=5;i<10;i++)
// scanf("%d",&pn[i]);
// for(i=0;i<10;i++)
// printf("%3d",pn[i]);
// printf("\n");
// free(pn);
// return 0;
// }