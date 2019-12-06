import java.util.Random;
public class array{
    public static void main(String[] args){
        Random rand=new Random();
         int max,min;
        int [][]nums=new int[3][4];
        for(int i=0;i<3;i++)
        for(int b=0;b<4;b++)
        nums[i][b]=rand.nextInt(100);
        max=min=nums[0][0];
        
        for(int i=0;i<3;i++)
        for(int b=0;b<4;b++){
            max=nums[i][b]>max?nums[i][b]:max;
            min=nums[i][b]<min?nums[i][b]:min;
        }

        for(int i=0;i<3;i++)
        for(int b=0;b<4;b++)
        System.out.print(nums[i][b]+"\t");

        System.out.print("\n"+"max="+max+",min="+min);
        
    }

}