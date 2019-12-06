#include "stdio.h"
int Pow(int x,int y){
int s=1;
for(int i=0;i<y;i++)
s*=x;
return s;
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int z=x;
   for(;x<=y;x++){
       for(int i=1;i<=x;i++){
    printf("%d\t",Pow(x,i));
    if(i==z)break;
       }
    putchar('\n');
   }
}