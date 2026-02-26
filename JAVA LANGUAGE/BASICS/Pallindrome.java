import java.util.*;
public class Pallindrome {
    static int n,rev=0,digit;
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        n=sc.nextInt();

        int copy=n;
        while(n>0)
        {
            digit=n%10;
            n=n/10;
            rev=rev*10+digit;
        }

        if(copy==rev)
            System.out.println("It is pallindrome.");
        else
            System.out.println("It is not a pallindrome.");
    }
}
