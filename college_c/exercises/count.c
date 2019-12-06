#include "stdio.h"

int main(){
    char c;
    int i,a[4]={0};

    while ((c=getchar())!='#')
    {
       if(c==' ')a[0]++;
       else
       if(c>='a'&&c<='z'||c>='A'&&c<='Z')a[1]++;
       else
       if(c>='0'&&c<='9')a[2]++;
       else
       a[3]++;
    }

    printf("space:%d\tword:%d\tnumber:%d\tdefault:%d\t",a[0],a[1],a[2],a[3]);
}