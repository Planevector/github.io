#include "stdio.h"

void max(int a[]){
     int x,y,k,t;
    for(x=0;x<3;x++){
        for(y=0;y<3;y++)
            if(a[y]>a[x])k=x;
            if(a[x]>a[x+1])
            {t=a[x];a[x]=a[x+1];a[x+1]=t;}        
    }
    printf("%5d",a[2]);
}


int strcompear(char c[],char c1[]){
    for(int i=0;c[i]!=0;i++);
    int i;
    for(i=0;c[i]==c1[i]&&c[i]!=0&&c1[i]!=0;i++);
    if(c[i]!=c1[i])
    return 0;
    else
    return 1;
}


void ScannerInt(int a[],int lengh){
    for(int i=0;i<lengh;i++)
    scanf("%d",&a[i]);
}

void ScannerDouble(double a[],int lengh){
    for(int i=0;i<lengh;i++)
    scanf("%lf",&a[i]);
}

/*printf("a=%p\n",a);
        puts("input type is int");
        int *x=NULL,y=100;
        x=&y;
        a=x;
        printf("\nx*=%d\t&x=%p\ta=%p\n*a=%p\n",*x,x,a,&a);
*/

/*void Scanner1(char s[],void *a,int lengh){

    if(strcompear(s,"int")){
        scanf("%d",(int *)a);

        printf("\n%d\n",*(int *)a);
        puts("input type is int");
    }
    else
        if(strcompear(s,"float")){
            puts("input type is float");
        }
        else
            if(strcompear(s,"double")){
                 puts("input type is double");
            }
            else
                if(strcompear(s,"long")){
                    puts("input type is long");
                }

    printf("a=%p\tlengh=%d\n",a,lengh);


}
*/

int main(){
    
    int a[5];
    ScannerInt(a,5);
    double b[5];
    ScannerDouble(b,5);
    for(int i=0;i<5;i++)
    printf("%d,%lf\t",a[i],b[i]);
   
}