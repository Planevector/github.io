#include "stdio.h"
#include "stdlib.h"
int main(){
    char c;
    int *px=(int *)malloc(4*sizeof(int));
    while ((c=getchar())!='#')
    {
       if(c==' ')px[0]++;
       else
       if(c>='a'&&c<='z'||c>='A'&&c<='Z')px[1]++;
       else
       if(c>='0'&&c<='9')px[2]++;
       else
       px[3]++;
    }
    printf("space:%d\tword:%d\tnumber:%d\tother:%d\t",px[0],px[1],px[2],px[3]);
    free(px);
   
}