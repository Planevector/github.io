#include "stdio.h"
#include "time.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"

long DownTo(long mdy){
    long sum;
    for(sum=0;mdy>0;mdy/=10)
        sum=sum*10+mdy%10;
        return sum;
}

int year(int y,int m){
    printf("  year return :");
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
       puts("31"); return 31;
    
    case 2:
    if(y%4==0&&y%100!=0||y%400==0){puts("29");return 29;}
        else
    {puts("28");return 28;}
    
    default:{puts("30");return 30;}
    }
}

void string_time(char *pc,long mdy){
    printf("string time mdy %ld\n",mdy);
    char swp[8];
    for(int i=0;mdy>0;i++){
        swp[i]=mdy%10+'0';
        mdy/=10;
    }

    for(int i=7,j=0;j<10;i--,j++){
        if(j==4||j==7){pc[j++]='-';}
        pc[j]=swp[i];
    }

    strcat(pc,".log");
    pc[14]=0;
    puts(pc);
}

int Now_time(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int year = 1900+timeinfo->tm_year;
    int month = 1+timeinfo->tm_mon;
    // printf("Now time return :%d",year*100+month);
    return year*100+month;
}

void time_remove(char *pc){
    long mdy;
     char *server1=(char *)malloc(sizeof(char)*31);
     char *server2=(char *)malloc(sizeof(char)*31);
    for(int y=Now_time()/100;y<Now_time()/100+1;y++){
        for(int m=(unsigned int)(Now_time()%100-1);m<(unsigned int)(Now_time()%100);m++){
            if(m==0)continue;
            for(int d=1;d<=year(y,m);d++){
                mdy=((y*100)+m)*100+d;
               strcpy(server1,"run-app-server-1/");
               strcpy(server2,"run-app-server-2/");
               string_time(pc,mdy);
               strcat(server1,pc);strcat(server2,pc);
               puts(server1);puts(server2);
               remove(server1);remove(server2);
               puts("delete success");
             //   printf("%d-%d-%d.log",y,m,d);
             //  sleep(1);
            }
        }
    }
}

void main(){
    char *px=(char *)malloc(14*sizeof(char));
   while (1){    
        time_remove(px);
        sleep(60*60*24*28);
       /* code */
   }
    // printf("main down to %ld",DownTo(10100002));
}