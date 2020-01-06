#include "stdio.h"

int main(){
  int sum,sum1;
  for(int x=2;x<=1000;x++){
      sum=sum1=0;
      for(int y=1;y<x;y++)
      if(x%y==0)sum+=y;
      
      for(int y=1;y<sum;y++)
      if(sum%y==0)sum1+=y;
      
      if(x==sum1)printf("%d->%d\n",x,sum);
  } 
    
}