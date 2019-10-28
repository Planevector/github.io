import java.util.Scanner;
 class sum2{
     public static void main(String[]args){
   int result=0,num,n;
      Scanner s=new Scanner(System.in);
      n=s.nextInt();
      int i=0;
      while(i<n){
          num=s.nextInt();
          result+=num;
        i++;
      }
    System.out.println(result);
   }
 }



