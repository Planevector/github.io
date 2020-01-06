#include "stdio.h"
#include "time.h"
#include "unistd.h"
#include "stdlib.h"
#include "threads.h"

// typedef struct Data Data;

// struct Data{
//     int num;
// };

 int n=b50000;
int CreateArray(int *px,int n){
    srand((unsigned)time(NULL));
    printf("origin array:");
    for(int i=0;i<n;i++){
    px[i]=rand()%1000;
    printf("%5d",px[i]);
    }
    putchar('\n');putchar('\n');
    return 0;
}

int SortOne(void *data){
   // scanf("%d",&n);
    int *px=(int *)malloc(sizeof(int)*n);
    CreateArray(px,n);
    time_t start,end;
    start=clock();
    for(int i=0;i<n-1;i++)
    for(int j=0,t;j<n-i-1;j++)
    if(px[j]>px[j+1]){t=px[j];px[j]=px[j+1];px[j+1]=t;}
    end=clock();
    printf("sorted array:");
    for(int i=0;i<n;i++)
    printf("%5d",px[i]);
    printf("\nSortOne use time  %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}

int SortTwo(void *data){
    //scanf("%d",&n);
    int *px=(int *)malloc(sizeof(int)*n);
    CreateArray(px,n);
    time_t end,start;
    start=clock();
    for(int x=0,k,y,t;x<n;x++){
        for(k=x,y=x+1;y<n;y++){
            if(px[y]<px[k])k=y;
        }
        if(px[k]!=px[x]){t=px[k];px[k]=px[x];px[x]=t;}
    }
    end=clock();
    printf("sorted array:");
    for(int i=0;i<n;i++)
    printf("%5d",px[i]);
    printf("\nSortTwo use time  %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);
}

int Test(void *data){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  CreateArray(a,n);
   for(int i=0;i<n;i++)
   for(int j=0,t;j<n-1-i;j++)
   if(a[j]>a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}
    printf("sorted array:");
    for(int i=0;i<n;i++)
    printf("%5d",a[i]);
}

void main(){

    thrd_t id;
    // if(thrd_create(&id,Test,NULL)!=thrd_success)
    //     puts("error");

    if(thrd_create(&id,SortOne,NULL)!=thrd_success)
        puts("error");


    if(thrd_create(&id,SortTwo,NULL)!=thrd_success)
        puts("error");


    if(thrd_detach(id))
    puts("error");

    // for(int i=0;i<10;i++)
    // printf("%d",i);

    
    while (1);
    

}