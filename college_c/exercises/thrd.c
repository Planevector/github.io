#include "stdio.h"
#include "stdlib.h"
#include "threads.h"

// void sort(int a[],int len);
// void Sort(int a[],int len);
// int len(int a[]);

// void main(){

   
//     //printf("%ld",sizeof(a));
// }

// void sort(int a[],int len){
//     for(int i=0;i<len-1;i++)
//     for(int x=0,t;x<len-i-1;x++)
//     if(a[x]>a[x+1]){t=a[x];a[x]=a[x+1];a[x+1]=t;}

//     for(int i=0;i<len;i++)
//     printf("%5d",a[i]);
//     puts(" ");
// }

// void Sort(int a[],int len){
//     for(int x=0,y,k,t;x<len;x++){
//         for(k=x,y=x+1;y<len;y++)
//         if(a[k]>a[y])k=y;       //find min number
//         if(a[k]!=a[x]){t=a[x];a[x]=a[k];a[k]=t;}    //if min number != a[x] swop

//     }

//     for(int i=0;i<len;i++)
//     printf("%5d",a[i]);
//     puts(" ");
// }

// int len(int a[]){
//     int i;
//     for(i=0;a[i]!=0;i++);
//     return i;
// }

int data(void *data){
   
}
struct DATA{
    int a;
    int b;  
}DATA;


int main(){
    thrd_t id;


}