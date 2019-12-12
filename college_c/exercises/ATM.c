#include "stdio.h"

int main(){
    int x=0,y=1,z,t;
    printf("%d %d ",x,y);
    for(int i=2;i<100;i++){

        if(i%2==0)z=x+y;
        else
        z=x-y;

        x=y;
        y=z;

       printf("%d ",z);
    }
}