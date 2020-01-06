#include "stdio.h"

int A(int a,int b){
    int z;
    if(a<b){z=a;a=b;b=z;}
    while(b>0){
       z=a%b;
       a=b;b=z;
    }
return a;
}

int B(int a,int b){
  return a*b/A(a,b);  //最小公倍数等于两数之积除以其最大公约数
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Minimum common multiple:%d\n",A(a,b));
    printf("greatest common divisor:%d\n",B(a,b));
}