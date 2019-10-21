#include "stdio.h"
#define PI 3.1415926

int main(){
        double r,d,s;
        char c;
        puts("select input radius or diameter: 1 radius 2 diameter");
        scanf("%c",&c);
        switch (c)
        {
        case '1' :puts("please input radius");
        scanf("%le",&r);
        printf("Perimeter :%lf",r*2*PI);
        printf("\tThe measure of area :%lf",r*r*PI);

        break;
        case '2' :puts("please input diameter");
        scanf("%le",&d);
        printf("Perimeter :%lf",d*PI);
        printf("\tThe measure of area :%lf",(d/2)*(d/2)*PI);
        break;
        
        default:puts("error");
            break;
        }

        return 0;
}
