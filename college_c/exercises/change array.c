#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
    int n;
    scanf("%d",&n);
    int *px=(int *)malloc(n*sizeof(int));

    srand((unsigned)time(NULL));
    printf("origin random array:\n");
    for(int i=0;i<n;i++){
    px[i]=rand()%10;
    printf("%d\t",px[i]);
    }
    putchar('\n');
    
    for(int i=0;i<n;i++){
 while(1){
    int a=px[i]++,x;
    for(x=0;x<i;x++)
    if(px[x]==a)break;
     if(x==i){
         px[i]=a;
         break;
        }
     }
 }
printf("changed:\n");
for(int i=0;i<n;i++)
printf("%d\t",px[i]);

}