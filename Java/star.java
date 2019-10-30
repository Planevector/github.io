public class star{
    public static void main(String []args){
        int i,j;
        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
                if(i>j)System.out.print(" ");
                else
                System.out.print("*");
            }
            System.out.println();
        }

    }

}