#include "stdio.h"
#define One 0.025
#define Two 0.028
double Sqrt(double x);

int main(){
    
    char type;
    int Deposit,take;
    float Amount_of_money,s=1;
    scanf("%c%d%d%f",&type,&Deposit,&take,&Amount_of_money);
 
 switch (type)
 {
 case '1':
    for(int i=0;i<take-Deposit;i++){
     s*=(1+One);}
     printf("%f",Amount_of_money*s);
     break;
 
 case '2':
    for(int i=0;i<take-Deposit;i++)
    s*=(1+Two);
    printf("%f",Amount_of_money*s);
    break;
 default:
 puts("type error");
     break;
 }




    return 0;
}

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