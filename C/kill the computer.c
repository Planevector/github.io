#include "stdio.h"
#include "time.h"
#include "threads.h"
#include "stdlib.h"

// int kill(void *argv){
//     int *px;
//     for(int i=0;i<1000000;i++){
//         px=(int *)malloc(sizeof(int)*1000);
//     }
// }

int ram(){
    while (1)
    {
        int *px=(int *)malloc(sizeof(int)*1000);
        putchar('*');
    
        /* code */
    }
      
}

int cpu(void *argv){
    thrd_t id;
    thrd_create(&id,cpu,NULL);
    putchar('#');
    cpu(NULL);
}

int kill(void *data){
    ram();
}

void main(){
    // thrd_t id;
    // for(int i=0;i<1000000;i++){
    // thrd_create(&id,kill,NULL);
    // printf("%d\n",i);
    // }
  thrd_t id;
  if(thrd_create(&id,kill,NULL)!=thrd_success)
  puts("error");

  cpu(NULL);
}