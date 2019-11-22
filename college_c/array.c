  #include "stdio.h"
#include "stdlib.h"

int main(){
    int a,b,c;
    int array[2][3][4];
    for(a=0;a<2;a++){
        for(b=0;b<3;b++){
            for(c=0;c<4;c++){
                array[a][b][c]=rand()%10;
            }
        }
    }

    for(a=0;a<2;a++){
        for(b=0;b<3;b++){
             for(c=0;c<4;c++)
    printf("%d",array[a][b][c]);
putchar('\n');
        }
   putchar('\n');
    }
}