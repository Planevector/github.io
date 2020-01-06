#include <stdio.h>
#include "stdlib.h"
#include "time.h"


void Swap(int arr[], int low, int high)
{
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}
 
int Partition(int arr[], int low, int high)
{
    int base = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= base)
        {
            high --;
        }
        Swap(arr, low, high);
        while(low < high && arr[low] <= base)
        {
            low ++;
        }
        Swap(arr, low, high);
    }
    return low;
}
 
void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int base = Partition(arr, low, high);
        QuickSort(arr, low, base - 1);
        QuickSort(arr, base + 1, high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *px=(int *)malloc(n*sizeof(int));
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
    px[i]=rand()%10000;
    clock_t start,end;
    start=clock();
    QuickSort(px,0,n-1); 
    end=clock();
    // printf("排序后的顺序是：\n");
    // for(int i=0;i<n;i++)
    //     printf("%5d",px[i]);    //输出排好序的数组
    printf("\nuse time %lf sec",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}