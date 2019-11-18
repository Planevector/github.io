#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 6


int main(){
    int *pNumber=(int *)malloc(N*sizeof(int));  //create memory
    if(!pNumber){                    //check 
        printf("Error");
    }
    srand((unsigned)time(NULL));                //use rand creat random number method 2 *(pNumber+variable)
    for(int i=0;i<N;i++){
 while(1){
    int a=rand()%10,x;
 for(x=0;x<i;x++)
    if(pNumber[x]==a)break;
     if(x==i){
    pNumber[i]=a;
     break;
        }
     }
 }

    // for(int i=0;i<N;i++){
    //     printf("%5d",pNumber[i]);       //print
    // }
    // puts(" ");

       
    for(int x=0;x<N;x++){          //sort
        for(int y=0,t;y<N-x;y++)
        if(pNumber[y]>pNumber[y+1])
        {t=pNumber[y];pNumber[y]=pNumber[y+1];pNumber[y+1]=t;}
    }
    for(int i=0;i<N;i++){
        printf("%5d",pNumber[i]);       //print
    }

    free(pNumber);          //release memory
    pNumber=NULL;           //restart
    
    return 0;
}