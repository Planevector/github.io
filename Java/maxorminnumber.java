import java.util.Scanner;
public class maxorminnumber{
    public static void main(String []args){
        int max,min;
        int []array=new int [5];
         Scanner scanner = new Scanner(System.in);
        array[0]=scanner.nextInt();
        max=min=array[0];
        for(int i=1;i<5;i++){
            array[i]=scanner.nextInt(); 
            if(array[i]>max)max=array[i];
            else
            min=array[i];
        }
        System.out.println("max"+max+"\t"+"min"+min);

        scanner.close();
    }
}