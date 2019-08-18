#include "stdio.h"
main(){
	int x,y;
	for(x=7;x>0;x-=2){
		for(y=0;y<7-x;y++)
		putchar(' ');
		for(;y<7;y++)
		printf("*");
		putchar('\n');
	} 
}