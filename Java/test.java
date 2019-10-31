public class test{
    public static void main(String[] args){
        System.out.println(x(9));
    }
    public static int x(int x){
        int s=1;
        for(int i=1;i<x;i++)
        s*=i;
        return s;
    }

}