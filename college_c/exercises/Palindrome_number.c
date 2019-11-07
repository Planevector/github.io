#include "stdio.h"
long palindrome(long x){
    long s=0;
    while(x>0){
        s+=x%10;
        s*=10;
        x/=10;
    }
    return s/10;
}

int main(){
    long a;
    scanf("%ld",&a);

    if(a==palindrome(a))printf("number is palindrome");
    else
         printf("number is not palindrome");

}