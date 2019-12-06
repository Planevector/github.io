#include "stdio.h"
#include "stdlib.h"
#include "time.h"

double b(){
    clock_t start=0,end=0;
    double cpu_time=0.;
    start=clock();

    int x,y,t;
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));

    srand((unsigned)time(NULL));
    for(long x=0;x<n;x++)
    a[x]=rand()%10000;

    for(x=0;x<n-1;x++){
        for(y=0;y<x;y++)
        if(a[y]<a[y+1])
        {t=a[y];a[y]=a[y+1];a[y+1]=t;}
    }
    for(x=0;x<n;x++)
    printf("%d\t",a[x]);
    puts(" ");

end=clock();
cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
return cpu_time;

}

double c(){
    clock_t start=0,end=0;
    double cpu_time;
    start=clock();

    long n;
    scanf("%ld",&n);
    long *px=(long *)malloc(n*sizeof(long));

    srand((unsigned)time(NULL));
    for(long x=0;x<n;x++)
    px[x]=rand()%10000;


for(long x=0,y,k,t;x<n-1;x++){
    for(k=x,y=k+1;y<n;y++)
    if(px[y]>px[k])k=y;
    if(px[x]!=px[k])
    {t=px[x];px[x]=px[k];px[k]=t;}
}

    for(long x=0;x<n;x++)
    printf("%ld\t",px[x]);

   puts(" ");

    end=clock();
    cpu_time=(double)(end-start)/CLOCKS_PER_SEC;

    return cpu_time;

}

// void a(){ol,
//     int x,y,a;
//     scanf("%d",&a);
//     for(y=0;y<a;y++){
// for(x=0;x<=y;x++){
//     putchar('$');
// }
// putchar('\n');
//     }
// }


int main(){
    // int *p=NULL;
    // int a=250;
    // p=&a;
    // printf("%p,%5d%5d",p,*p,a);

    // *p=234;
    // printf("\n%d,%d",*p,a);
    // return 0;
//a();
//b();

printf("%lfsec\n\n",b());
printf("%lfsec\n\n",c());

// int i;
// i=0;end:
// if(i<10){
//     printf("123\t");
//     i++;
//     goto end;
// }

}

