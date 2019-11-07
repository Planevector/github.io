import java.util.Scanner;
public class calculation{
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        double x=scanner.nextDouble();
        char c=scanner.next().charAt(0);
        double y=scanner.nextDouble();
        calculations(x,c,y);

    }

    public static void calculations(double a,char c,double b){
        switch(c){
            case '+':
            System.out.println(a+"+"+b+"="+(a+b));
            break;
            case '-':
            System.out.println(a+"-"+b+"="+(a-b));
            break;
            case '*':
            System.out.println(a+"*"+b+"="+(a*b));
            break;
            case '/':
            System.out.println(a+"/"+b+"="+(a/b));
            break;

        }
    }
}