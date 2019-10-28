import java.util.Scanner;
public class sum{
    public static void main(String []args){
        int sum=0,n;
        Scanner scanner=new Scanner(System.in);
        n=scanner.nextInt();
        int i=0;
        while(i<n){
            System.out.println("NUM"+(i+1));
            sum+=scanner.nextInt();
            i++;
        }
        System.out.println("sum="+sum);
    }
}