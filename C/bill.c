#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "time.h"

typedef struct Bill Bill;

struct Bill
{ 
    char Id[15];
    char Date[20];
    char Name[100];
    double Money;
    char PayMethod[50];
    int Amount;
};

typedef enum Month{
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
}Month;


void Reverse_Number(long *x,long *y){
    
   // printf("Reverse_Number:[x%ld] [y%ld]",*x,*y);
    long sum=0;
    while(*x>0){
        sum=sum*10+*x%10;
        *x/=10;
       // printf(" x[%ld] ",*x);
    }
    *x=sum;sum=0;
   // printf("%ld\n",*x);
    while(*y>0){
        sum=sum*10+*y%10;
        *y/=10;
        //printf(" y[%ld] ",*y);
    }
    *y=sum;sum=0;
   // printf("%ld\n",*y);

}

void Convert_String_Id(long *x,long *y,char Id[]){
   // printf("Convert String date:%ld time:%ld\n",*x,*y);
    int i;
    for(i=0;*x>0;i++,*x/=10){
    Id[i]=*x%10+'0';
   // printf(" [%ld] ",*x%10);
    }
    //puts(Id);
    while (*y>0){
        Id[i++]=*y%10+'0';
      //  printf(" [%ld] ",*y%10);
       *y/=10;
    }
   i = 0;
   while (Id[i])i++;
   //printf(" [%d] \n",i);
   if(i!=14){

        int x;Id[13]='0';
    //    printf(" I!=14[%c] \n",Id[12]);
       for(x=12;x>=8;x--){
          Id[x+1]=Id[x];
       // printf(" [%c] ",Id[x]);
       }

       Id[x+1]='0';
       Id[14]=0;

   }
      
}

void Convert_String_Date(char Date[],char Id[]){
    for(int i=0,x=0;Id[i];i++,x++){
        Date[x]=Id[i];
       x==3 || x == 6 ? Date[++x]='-' : x;
       x==9 ? Date[++x]=' ' : x;
       x==12 || x==15 ? Date[++x]=':' : x;
    }
    Date[19]=0;
   // puts(Date);
}

void Create_Month(int month,char *Pmemonth){
   // puts("<");
     switch (month) {
   case January: strcpy(Pmemonth,"January");break;  //puts("\"January\"[");
   case February: strcpy(Pmemonth,"February");break;    //puts("\"January\"[");
   case March: strcpy(Pmemonth,"March");break;         // puts("\"March\"[");
   case April: strcpy(Pmemonth,"April");break;     // puts("\"April\"[");
   case May: strcpy(Pmemonth,"May");break;     // puts("\"May\"[");
   case June: strcpy(Pmemonth,"June");break;//puts("\"June\"[");
   case July: strcpy(Pmemonth,"July");break;//puts("\"July\"[");
   case August: strcpy(Pmemonth,"August");break;//puts("\"August\"[");
   case September: strcpy(Pmemonth,"September");break;//puts("\"September\"[");
   case October: strcpy(Pmemonth,"October");break;//puts("\"October\"[");
   case November: strcpy(Pmemonth,"November");break;//puts("\"November\"[");
   case December: strcpy(Pmemonth,"December");break;//puts("\"December\"[");
   }
}

long File_Len(char *Pname){
    long Len;
    FILE *PFile;
    if(!(PFile=fopen(Pname,"r+"))){
        puts("File_Len_error");
        return 1;
    }
    for(Len=0;fgetc(PFile)!=EOF;Len++);
    fclose(PFile);
    return Len;
}

int String_Compear(char *a,char *b,int len){
    int x,y;
    for(x=0;a[x];x++){
        int z=0;
        for(y=x;y<x+len;y++){
            if(a[y]!=b[z++])break;
        }
      // printf("y=%d-->x=%d-->x+len=%d\n",y,x,x+len);
        if(y==x+len)return 1;
    }
    return 0;

}

void File_Compear(long file_len,char *Pname,char *Pmonth){
  //  printf("file len : %ld\n",file_len);
     FILE *PFile;
    if(!(PFile=fopen(Pname,"r+"))){
        puts("File_Len_error");
        exit(0);
    }
    char *Pf=(char *)malloc(sizeof(char)*file_len);
    if(!Pf){puts("File_COmpear pf error");exit(0);}

    for(int len=0;(Pf[len]=fgetc(PFile))!=EOF;len++);

    if(!String_Compear(Pf,Pmonth,strlen(Pmonth))){
        puts("create month");
        fprintf(PFile,"\n$>\"%s\"<$\n",Pmonth);
    }

    fclose(PFile);
}

void main(){
    
    char *Pname = "2020_billing_template.bill";
    int select_PayMethod;
    time_t t;
    struct tm *lt;
    struct Bill bill;
    time (&t);
    lt = localtime(&t);
    char *Pmonth=(char *)malloc(sizeof(char)*20);
    if(!Pmonth){puts("pmonth error");exit(0);}

    Create_Month(lt->tm_mon+1,Pmonth);
    File_Compear(File_Len(Pname),Pname,Pmonth);

    puts("Welcome To PlaneVector Bill Program");

    printf("Please Enter Name(商品名称):");
    scanf("%s",bill.Name);
    
    end2:
    printf("Please Enter Amount(数量):");
    scanf("%d",&bill.Amount);
    if(bill.Amount<0){
         puts("Cannot enter a number less than 0 !!!");
        goto end2;
    }

    end1:
    printf("Please Enter Money(金额:￥):");
    scanf("%le",&bill.Money);
    if(bill.Money<0){
        puts("Cannot enter a number less than 0 !!!");
        goto end1;
    }

    end:
    printf("Please Select PayMethod(支付方式)\n\
                   └── (1:WeChat,2:Alipay,3:YinLian,4:other):");
    scanf("%d",&select_PayMethod);
    switch (select_PayMethod){
        case 1:strcpy(bill.PayMethod,"WeChat");break;
        case 2:strcpy(bill.PayMethod,"Alipay");break;
        case 3:strcpy(bill.PayMethod,"YinLian");break;
        case 4:printf("Please Enter PayMethod:");scanf("%s",bill.PayMethod);break;
        default:puts("Input Error Please Enter Again");goto end;
    }

    long date = ((lt->tm_year+1900)*100+lt->tm_mon+1)*100+lt->tm_mday;
    long time = ((lt->tm_hour)*100+lt->tm_min)*100+lt->tm_sec;
   // printf(" [%ld] \n",time);
    long *Date = &date,*Time = &time;

    // printf("%ld->[%ld]\n",date,*Date);
    // printf("%ld->[%ld]\n",time,*Time);


    Reverse_Number(Date,Time);
    Convert_String_Id(Date,Time,bill.Id);
    Convert_String_Date(bill.Date,bill.Id); 

    FILE *Pfile = fopen(Pname,"a+"); 
    if(!Pfile){exit(0);
    puts("open file fail");}
    fseek(Pfile,-5l,SEEK_CUR);
    fprintf(Pfile,"{\"Id(账单编号)\":\"%s\" , \"Date(日期)\":\"%s\" , \"Name(商品名称)\":\"%s\" , \"Amount(数量)\":\"%d\" , \"Money(金额:￥)\":\"￥%.2lf\" , \"PayMethod(支付方式)\":\"%s\"},\n",bill.Id,bill.Date,bill.Name,bill.Amount,bill.Money,bill.PayMethod);

    printf("{\"Id(账单编号)\" : \"%s\",\"Date(日期)\" : \"%s\",\"Name(商品名称)\" : \"%s\",\"Amount(数量)\" : \"%d\",\"Money(金额:￥)\" : \"￥%.2lf\",\"PayMethod(支付方式)\" : \"%s\"},\n",bill.Id,bill.Date,bill.Name,bill.Amount,bill.Money,bill.PayMethod); 
    //printf("  ]\n>\n");
    // printf("bill.Id:%s\n",bill.Id);
    // printf("bill.Date:%s\n",bill.Date); 
   
    fclose(Pfile);
   // printf ( "%d-%d-%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday,lt->tm_hour, lt->tm_min, lt->tm_sec);
}
