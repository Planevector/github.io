#include "time.h"
#include "stdio.h"
#include "stdlib.h"
void sort(){
    int a;
    scanf("%d",&a);
    int *array=(int *)malloc(a*sizeof(int));
    clock_t start=0,end=0;
    srand((unsigned)time(NULL));
    for(int i=0;i<a;i++)
    array[i]=rand()%100;

    start=clock();

    for(int x=0;x<a-1;x++)
        for(int y=0,t;y<a-x-1;y++)
        if(array[y]>array[y+1])
        {t=array[y];array[y]=array[y+1];array[y+1]=t;}

    end=clock();

    for(int i=0;i<a;i++){
         printf("%5d",array[i]);
    }
    printf("\nuse time-->>[%lf]",(double)(end-start)/CLOCKS_PER_SEC);

    array=NULL;
    free(array);
}

void c(){
    int a[5]={1,4,2,5,3};
    int max=a[0];
    for(int i=1;i<5;i++)
    max=max>a[i] ? max :a[i];
    printf("\nmax=%d\n",max);
}

void d(){
    int a[5]={1,4,2,5,3};

    int max=a[0],n=0;
    for(int i=1;i<5;i++){
        if(max>a[i])max=a[i];
        n++;
    printf("max=%d\n",n);
    }
}

void e(){
    int a[5]={1,4,2,5,3};
    int max=a[0],min=a[0];
    for(int i=1;i<5;i++){
    max=max>a[i] ? max :a[i];
    min=min<a[i] ? min :a[i];
    }
    printf("max=%d\n",max-min);
}

void f(){
    int a[5]={1,4,2,5,3};
    int b[5]={1,4,2,5,3};
    int c[5]={1,4,2,5,3};
    for(int i=0;i<5;i++)
    c[i]=a[i]+b[i];
    for(int i=0;i<5;i++)
    printf("%5d\n",a[i]);
}

void g(){
    int a[20]={1,4,2,5,3,1,4,2,5,3,1,4,2,5,3,1,4,2,5,3};
    double sum=0,count;
    for(int i=0;i<20;i++){
    sum+=a[i];
    count++;
    }
    printf("%lf\n",sum/count);
}

void x(){
    int a[20]={1,4,2,5,3,1,4,2,5,3,1,4,2,5,3,1,4,2,5,3};
    int count=0;
    for(int i=0,x;i<20;i++){
        for(x=2;x<a[i];x++){
            if(a[i]%x==0)break;
        }
        if(x==a[i])count++;
    }
    printf("%d\n",count);
    
}

int main(){
  c(),d(),e(),f(),g();
}
//          int a,b,c;
//         int array[2][3][4];
//         for(a=0;a<2;a++){
//             for(b=0;b<3;b++){
//                 for(c=0;c<4;c++){
//                     array[a][b][c]=rand()%10;
//                 }
//             }
//         }

//         for(a=0;a<2;a++){
//             for(b=0;b<3;b++){
//                 for(c=0;c<4;c++)
//         printf("%d",array[a][b][c]);
//     putchar('\n');
//             }
//     putchar('\n');
//         }
