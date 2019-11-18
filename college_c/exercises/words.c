#include "stdio.h"
#define length 1000

int  compear(char c,char String[]){
   int i=0,com=0;
    while (String[i])
    {
        if(String[i++]==c)
        com=1;
    }
    return com;
}

int main(){

    int count,y=0,f=0,z=0;
    char String[length],c;
    char list[]="\"\'\t,.;:!? \n";
    char WordConut[length][3];
    fgets(String,length,stdin); 

    for(int i=0;String[i];i++){
        printf("%c**%d**\n",String[i],compear(String[i],list));
    if(compear(String[i],list)==0){
        WordConut[y++][3]=String[i++];
        i--;
    }else{
        WordConut[y++][3]=' ';
         printf("\n");
 continue;
    }
    }

   for(int i=0;WordConut[i][3];i++)
   putchar(WordConut[i][3]);

return 0;
}

/*
{
     int count,y=0,f=0;
    char String[length],c;
    char list[]="\"\'\t,.;:!? \n";
    for(int i=0;list[i];i++){
        putchar(list[i]);
        putchar('*');
    }
    char WordConut[length][3];
    fgets(String,length,stdin);
    for(int i=0,c=' ';String[i]!=0;c=String[i++]){
        int x=0;while(list[x++]){
        if(list[x]==c&&String[i]!=list[x]){
            int z=0;
            printf("\n**\n%c\n**\n",String[i]);
            while(list[x++]!=String[i]&&String[i]!=0){
                printf("COMPEAR=%d\n",compear(String[i],list));
                if(compear(String[i],list))break;
                WordConut[y++][3]=String[i++];
               printf("String=%c,WordCount=%c\tf=%d\n",String[i-1],WordConut[y-1][3],f++);
            }
         break;
        }
     }
    }
    WordConut[y][3]=0;
   printf("\n\nWordcount=");
 for(int i=0;WordConut[i][3]!=0;i++)
 putchar(WordConut[i][3]);
 

}
*/