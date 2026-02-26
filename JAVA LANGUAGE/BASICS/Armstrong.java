import java.util.*;
public class Armstrong {
    static int n,sum,digit;
    public static void main(String []args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        n=sc.nextInt();

        int copy=n;
        while(n>0)
        {
            digit=n%10;
            n=n/10;
            sum=sum+(int)Math.pow(digit,3);
        }

        if(copy==sum)
            System.out.println("It is Armstrong number.");
        else
            System.out.println("It is not an Armstrong number.");
    }
}
