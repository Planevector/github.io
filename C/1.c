#include "stdio.h"
#include "time.h"
#include "unistd.h"
#include "string.h"
#include "stdlib.h"

int File_Len(char *PfName);
void File_Name(char *pGetDate);
int String_Len(char *String_Name);
int String_Compear(char *a,char *b,int len);
int Read_File(char *File_Name,char *pm);
int File_Statistics(char *pm,char *pTemp,char *swp);
int Write_File(char *pSave,char *FileName,char *pm,char *Write_Time);

int main(){

    //String_Compear("1234","12",2)==0 ? puts("no") : puts("yes");


    
    char *pSave="save.txt";

    char *pName=(char *)malloc(14*sizeof(char));
    if(!pName){puts("GetDate_error");return 0;}


    File_Name(pName);

    char *pm=(char *)malloc(File_Len(pName)*sizeof(char));
    if(!pm){puts("pm_error");return 0;}

    char *pTemp=(char *)malloc(File_Len(pName)*sizeof(char));
    if(!pTemp){puts("pTemp_error");return 0;}
    
    char *pSwp=(char *)malloc(File_Len(pName)*sizeof(char));
    if(!pSwp){puts("pTemp_error");return 0;}

    printf("Len=%d\n\n",File_Len(pName));
   // sleep(3600*24);

    Read_File(pName,pm)==0 ? puts("Read_error") : puts("Read-->success");
    printf("\nFile_Statistics-->%d",File_Statistics(pm,pTemp,pSwp));
    Write_File(pSave,pName,pm,pName)==0 ? puts("Write_error") : puts("Write-->success");

    
  

    pm=NULL;
    pSwp=NULL;
    pName=NULL;

    free(pm);
    free(pSwp);
    free(pName);
}

void File_Name(char *pName){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int year,month,day;
    long s=0,sum=0;
    year = 1900+timeinfo->tm_year;
    month = 1+timeinfo->tm_mon;
    day = timeinfo->tm_mday;
    s=(year*100+month)*100+day;

    for(int i=0;s>0;i++){
        sum=sum*10+s%10;
        s/=10;
    }
    for(int i=0;i<10;i++){
    if(i==4)pName[i++]='-';
    if(i==7)pName[i++]='-';
    pName[i]=sum%10+'0';
    sum/=10;
    }
    strcat(pName,".log");
}

int Read_File(char *File_Name,char *pm){
    FILE *pFile=fopen(File_Name,"r+");
    if(!pFile)return 0;
    for(int i=0;(pm[i]=fgetc(pFile))!=EOF;i++);
    fclose(pFile);
    return 1; 
}

int Write_File(char *pSave,char *File_Name,char *pm,char *Write_Time){
    clock_t start=0,end=0;
    start=clock();
    int Len=File_Len(File_Name);
    char *pch="\n\n\n\n";

    FILE *pFile=fopen(pSave,"a+");
    if(!pFile)return 0;

    for(int i=0;i<Len;i++)
    fprintf(pFile,"%c",pm[i]);

    end=clock();
    fprintf(pFile,"%s															     use%lfsec\n",pch,(double)(end-start)/CLOCKS_PER_SEC);
    fprintf(pFile," 															     write time:");
    for(int i=0;i<10;i++)
    fprintf(pFile,"%c",Write_Time[i]);
    fprintf(pFile,"\n\n");
    putchar('\n');
   // remove(File_Name);
    return 1;

}

int File_Len(char *PfName){
    int Len;
    FILE *PFile;
    if(!(PFile=fopen(PfName,"r+"))){
        puts("File_Len_error");
        return 1;
    }
    for(Len=0;fgetc(PFile)!=EOF;Len++);
    return Len-1;
}

int File_Statistics(char *pm,char *pTemp,char *swp){
    int  nword[10000]={0};
    char *pList=" \n";
    strcpy(swp,pm);
    char *pWord=strtok(swp,pList);
    int i,x=0,word_count=0;
    size_t new_word=1;
   for(i=0;pWord!=NULL;i++){
     // printf("\n\npWord-->[%s]                                          ",pWord);
     // printf("\n[%d]\n",String_Compear("1234567","23",2));

      if(String_Compear(pm,pWord,String_Len(pWord))){
               nword[i]++;       
             printf("\n\nString_Compear(pm,pWord,String_Len(pWord))-->%d\n\t[pWord=%s]\t[swp=%s]\n\n",String_Compear(pm,pWord,String_Len(pWord)),pWord,swp);
               new_word=0;
      }
      if(new_word){
           printf("[x=%d]-->{",x++);
           puts(pTemp);
          strcat(pTemp,pWord);
          nword[word_count++]++;
      }else
      new_word=1;
    
 // printf("[i=%d]-->>[%d]-->>\n",i,nword[i]);
        pWord=strtok(NULL,pList);  
             
  }
   
   //printf("\nnword[%d]                                             ",nword[1]);

 if(!pWord){puts("\ntoken-->EOF");return i;}

}

int String_Len(char *String_Name){
    int i;
    for(i=0;String_Name[i]!=0;i++);
    return i; 
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