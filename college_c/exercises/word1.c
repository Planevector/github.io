#include "stdio.h"

int main(){
    char c;
   while(1){
        c=getchar();
    if(c>='a'&&c<='z'){
        printf("%d\n",c-96);
    }
    else
    if(c>='A'&&c<='Z')    
    printf("%d\n",c-64);
   }

    return 0;
}

/*
if(c>='a'&&c<='z'){
        printf("%d",c-('a'-1));
  }  
    else
    if(c>='A'&&c<='Z')    
    printf("%d",c-('A'-1));
*/

