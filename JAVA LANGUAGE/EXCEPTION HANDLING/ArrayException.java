import java.util.*;
public class ArrayException {
    public static void main(String[] args) {
        int a[]=new int[5];
        Scanner sc=new Scanner(System.in);
        try {
            for(int i=0;i<6;i++)
            {
                System.out.println("Input a number: ");
                a[i]=sc.nextInt();
            }
        }
        
        catch(Exception e) {
            System.out.println("Input Error: "+ e.getMessage());
        }
    }
}
