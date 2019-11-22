#include "stdio.h"
#include "time.h"
#include "stdlib.h"

int Pow(int a,int b){
    int s=1;
    for(int i=0;i<b;i++)
        s*=a;
        return s;
}   
int main(void){
    int indexmax=1,indexnow=1;
    long max=0,sum=0;
    int N;
    scanf("%d",&N);
    int *px=(int *)malloc(N*sizeof(int));
    srand((unsigned)time(NULL));
    for(int i=0;i<N;i++)
    px[i]=rand()%10;
    for(int i=1;i<=N;i++){
        int x=Pow(2,indexnow)-1;
        printf("x=%d,i=%d,",x,i);
         sum+=px[i];
        if(i>=x){
         if(max<sum)indexmax=indexnow;
         else
         indexmax=indexmax;
          if(max<sum)max=sum;
          else
          max=max;
           indexnow++;
           sum=0;
           printf("ifsum%ld,indexnow=%d,max=%ld,",sum,indexnow,max);
        }
        printf("px[%d]=%d,sum=%ld,\n",i,px[i],sum);
    }
    printf("\n%d\n",indexmax);       
}