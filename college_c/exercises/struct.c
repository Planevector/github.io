#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define N 5
typedef struct Two_Fork_Tree Two_Fork_Tree;

void List_Two_Fork_Tree(Two_Fork_Tree *pTFT);
Two_Fork_Tree Add_Two_Fork_Tree(long value,Two_Fork_Tree *pTFT);
Two_Fork_Tree *Create_Two_Fork_Tree(long value);

struct Two_Fork_Tree{
    /* data */
    long item;
    int count;
    Two_Fork_Tree *pLeft;
    Two_Fork_Tree *pRight;
};

int main(){
    //long a[N];
    Two_Fork_Tree *pRoot=NULL;
    // srand((unsigned)time(NULL));
    // for(int i=0;i<N;i++)
    // a[i]=rand()%100;
   int n=0;
   for(int i=0;i<N;i++){
       scanf("%d",&n);
       if(!pRoot)
       Create_Two_Fork_Tree(n);
       else
       Add_Two_Fork_Tree(n,pRoot);
   }
    List_Two_Fork_Tree(pRoot);
    free(pRoot);
}

Two_Fork_Tree *Create_Two_Fork_Tree(long value){
    Two_Fork_Tree *pCTF=(Two_Fork_Tree *)malloc(value*sizeof(Two_Fork_Tree));
    pCTF->item=value;
    pCTF->count=1;
    pCTF->pLeft=pCTF->pRight=NULL;
    return pCTF;
}

Two_Fork_Tree Add_Two_Fork_Tree(long value,Two_Fork_Tree *pTFT){
    if(!pTFT)   return *Create_Two_Fork_Tree(value);
    if(value==pTFT->item){pTFT->item++;return *pTFT;}
    if(pTFT->item>value){
        if(!pTFT->pLeft){pTFT->pLeft=Create_Two_Fork_Tree(value);return *pTFT->pLeft;}
        else
            Add_Two_Fork_Tree(value,pTFT->pLeft);
    }
    else{
        if(!pTFT->pRight){pTFT->pRight=Create_Two_Fork_Tree(value);return *pTFT->pRight;}
        else
        Add_Two_Fork_Tree(value,pTFT->pRight);
    }

}

void List_Two_Fork_Tree(Two_Fork_Tree *pTFT){
    if(pTFT->pLeft)
    List_Two_Fork_Tree(pTFT->pLeft);
    printf("%10d x %10ld",pTFT->count,pTFT->item);
    if(pTFT->pRight)
    List_Two_Fork_Tree(pTFT->pRight);
}