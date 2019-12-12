#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
    
    int *px=(int *)malloc(5*sizeof(int));

    for(int i=0;i<10;i++){
        scanf("%d",&px[i]);
        if(i>=5)px=realloc(px,10*sizeof(int));
        if(!px){
            puts("error");
            return 1;
        }
    }

    for(int i=0;i<10;i++)
    printf("%d\t",px[i]);


}