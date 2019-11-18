import java.util.Scanner;
public class help{
    public static void main(String[] args){
        Scanner S=new Scanner(System.in);
        int a,b,s=0,s1=0;
        a=S.nextInt();
        b=S.nextInt();
        for(int i=0;i<b;i++){
           s=s*10+a;
           s1+=s;
           System.out.print(s+"+");
        }
        System.out.print('\b'+"="+s1);
        S.close();
    }
}