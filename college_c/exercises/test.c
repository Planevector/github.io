#include <stdio.h>
#include <math.h>
#include <string.h>

char menu()
{
    char n;
    do{
 
   printf("学生成绩管理系统\n");
   printf("1:录入学生成绩\n");
   printf("2:显示学生成绩\n");
   printf("3:查询学生成绩\n");
   printf("4:修改学生成绩\n");
   printf("5:删除学生记录\n");
   printf("0:退出该系统\n"); 
   printf("请在0-5之间选择\n");
   n=getchar();
  }while(n>=0&&n<=5);
    return  n;
}


void main()
{
	int i=0,rs=0,j,n;
	char xm[100][20],xh[100][20];
double math[100][20],eng[100][20],phy[100][20];
	char h;
char cx[20];
 do
 {
	 h=menu(); 
	 switch(h)
	  {
	   case '1':
		      { 
			
			   printf("请输入第%d学生姓名：",rs+1);
			   scanf("%s",xm[i]);
               //gets(xm[i]);
			   printf("请输入第%d学生学号：",rs+1);
               scanf("%s",xh[i]);
			  // gets(xh[i]);
			   printf("请输入第%d学生数学成绩：",rs+1);
                 scanf("%lf",&math[i][i]);
			   printf("请输入第%d学生英语成绩：",rs+1);
			   scanf("%lf",&eng[i][i]);
			   printf("请输入第%d学生物理成绩：",rs+1);
			   scanf("%lf",&phy[i][i]);
             i++;rs++;
			 
	           break;
		      }
	   case '2':
		      {
			 
              for(i=0;i<rs;i++)
			   {printf("姓名：%s",xm[i]);
			   printf("学号：%s",xh[i]);
			   printf("数学：%f",math[i][i]);
			   printf("英语：%f",eng[i][i]);
			   printf("物理：%f",phy[i][i]);
               printf("\n");}
		      
	           break;
		      }
	   case '3':
		      { 
			       printf("请输入要查询的学生学号：");
		         do{scanf("%s",cx);}while(strcmp(cx,"")==0);
		         for(i=0;i<rs;i++)
                  {if(strcmp(xh[i],cx)==0) break;}
		         if(i==rs) printf("查无此人！\n");
		         else printf("姓名：%s 学号：%s 数学：%lf 英语：%lf 物理：%lf",xm[i],xh[i],math[i][i],eng[i][i],phy[i][i]);
			  
		       break;
		      }
	   case '4':
		      {  
              
			   printf("选了4\n");
			   
               break;
		      }
	   case '5':
		      {
			
			   printf("选了5\n");
	           break;
		      }
	 }
 }while(h!='0');
}
