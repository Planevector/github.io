#include "stdio.h"
int _1(char c){
    switch (c)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u': return 1;
    break;
    default: return 0;
    break;
    }
}
int _2(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    return 0;
    else
    return 1;
}
int main(){
    char c;
    c=getchar();
    if(_1(c))
    puts("yes vowel");
    else
    puts("no vowel");
return 0;
}