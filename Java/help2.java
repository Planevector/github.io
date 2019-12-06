import java.util.Random;

public class help2{
    public static void main(String []args){
         int[] a=new int [10];
         int b;
         for(int i=0;i<10;i++)
         a[i]=0;
        Random rand=new Random();
        for(int i=0;i<100;i++){
            b=rand.nextInt(10);
            for(int x=0;x<10;x++)
            if(x==b)a[x]++;
        }
        for(int x=0;x<10;x++)
        System.out.print(x+":"+a[x]+"\t");
    }
   
}