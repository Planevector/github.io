#include "stdio.h"
#include "unistd.h"
#include "threads.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

void _1(){
    int n,d1,d2,d3,d4;
    scanf("%d",&n);
    d1=n%10;
    d2=(n%100)/10;
    d3=(n%1000)/100;
    d4=(n%10000)/1000;
    printf("%d%d%d%d",d1,d2,d3,d4);
}

void _2(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",a*100+b*10+c);
}

void _3(){
    char c;
    c=getchar();
    putchar(c+32);
}

void _4(){
    int n;
    scanf("%d",&n);
    switch (n/10)
    {
        case 10: case 9:
        putchar('A');break;
        case 8:
        putchar('B');break;
        case 7:
        putchar('C');break;
        case 6:
        putchar('D');break;
    default:putchar('E');
        break;
    }
}

void _5(){
    int a=0,b=0,c=0;
    int *px=(int *)malloc(20*sizeof(int));
    srand((unsigned)time(NULL));
    for(int i=0;i<20;i++){
    px[i]=rand()%100-50;
    printf("%5d",px[i]);
    }
    for(int i=0;i<20;i++){
        if(px[i]>0)a++;
        else
        if(px[i]<0)b++;
        else
        c++;
    }
    printf("\na->%d b->%d c->%d",a,b,c);
}
int _6Adjunct(int a){
    int s=1;
    for(int i=1;i<=a;i++)
    s*=i;
    return s;
}

void _6(){
    double e=1,value;
    int x;
   for(x=1;(value=1.0/_6Adjunct(x))>10E-6;x++){
       e+=value;
   }
   printf("%lf",e);
}

void _7(){
    int count=0;
    for(int a=7;a<91;a++){
        if(a%3==0&&a%2==1)count++;
    }
    printf("%d",count);
}

void _8(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
        putchar('$');
        putchar('\n');
    }
}

void Swap(int arr[], int low, int high){
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}
 
int Partition(int arr[], int low, int high){
    int base = arr[low];
    while(low < high){
        while(low < high && arr[high] >= base){
            high --;
        }
        Swap(arr, low, high);
        while(low < high && arr[low] <= base){
            low ++;
        }
        Swap(arr, low, high);
    }
    return low;
}
 
void QuickSort(int arr[], int low, int high){
    if(low < high){
        int base = Partition(arr, low, high);
        QuickSort(arr, low, base - 1);
        QuickSort(arr, base + 1, high);
    }
}


void _9Adjunct(int *px,int n){
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
    px[i]=rand()%1000;
}

int _9(void *argv){
    int n=30000;
    //scanf("%d",&n);
    int *px=(int *)malloc(n*(sizeof(int)));
    _9Adjunct(px,n);
    time_t start,end;

    for(int x=0;x<3;x++){
    switch (x){
    case 0:{
    start=clock();
    QuickSort(px,0,n-1); 
    end=clock();
    // for(int i=0;i<n;i++)
    // printf("%5d",px[i]);    //输出排好序的数组
    printf("\nkuai su sort use time %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);

        } sleep(2);break;
        case 1:{
    start=clock();
    for(int i=0;i<n-1;i++)
    for(int j=0,t;j<n-i-1;j++)
    if(px[j]>px[j+1]){t=px[j];px[j]=px[j+1];px[j+1]=t;}
    end=clock();
    // for(int i=0;i<n;i++)
    // printf("%5d",px[i]);
    printf("\nmao pao sort use time %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);

        } sleep(2);break;
        case 2:{
        start=clock();
        for(int i=0,j,k,t;i<n;i++){
        for(k=i,j=i+1;j<n;j++)
        if(px[k]<px[j])k=j;
        if(px[k]!=px[i]){t=px[k];px[k]=px[i];px[i]=t;}
    }
    end=clock();
    // for(int i=0;i<n;i++)
    // printf("%5d",px[i]);
    printf("\ncha ru sort use time  %lf sec\n\n",(double)(end-start)/CLOCKS_PER_SEC);

        } sleep(2);break;

        }

    }
   
}
int _10(int n){
    switch (n)
    {
    case 0: return 0;
    case 1: case 2: return 1;
    }
    return (_10(n-1)+_10(n-2));
}

int main(){
    
    thrd_t thr;
    void *a;
    if(thrd_create(&thr,_9,NULL)!=thrd_success){
        puts("ERROR");
        return 0;
    }
    if(thrd_detach(thr)!=thrd_success){
        puts("ERROR");
        return 1;
        return 0;
    }

    for(int i=0;i<3;i++){
        puts("hello");sleep(2);
    }
}