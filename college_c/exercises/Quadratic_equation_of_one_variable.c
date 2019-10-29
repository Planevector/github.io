#include "stdio.h"

double Sqrt(double x){
    double r,l,m,i;
    for(i=l=0,r=x,m=(1+r)/2;i<100;m=(l+r)/2,i++){
        if(m*m>x){
            r=m;
            m=(l+m)/2;
        }
        else
            if(m*m<x){
                l=m;
                m=(l+r)/2;
            }
    }
    return m;
}

int main(){

    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);

    if(b*b-4*a*c<0){
        printf("invalid equation");
    }
    else{ 
        float dlt=b*b-4*a*c;
        printf("x1=%f\t",(-b+Sqrt(dlt)/a/2));
        printf("x2=%f",(-b-Sqrt(dlt)/a/2));
    }

    return 0;
}