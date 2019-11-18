#include "stdio.h"
#include "stdlib.h"

int main(){
    int *pNumber=(int *)malloc(10*sizeof(int));  //create memory
    if(pNumber){                    //check 
        printf("Error");
    }


    free(pNumber);          //release memory
    pNumber=NULL;           //restart
    
    return 0;
}