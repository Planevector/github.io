import java.util.Scanner;
public class compear{
    public static void main(String [] args){
        int a,b,t;

        Scanner scanner=new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        if(a>b){
    t=a;a=b;b=t;
        }

        System.out.println(a+"\t"+b);
        
    }
}