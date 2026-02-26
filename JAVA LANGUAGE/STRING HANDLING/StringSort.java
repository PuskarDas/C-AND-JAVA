import java.util.*;
public class StringSort {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.print("Enter a string to sort: ");
        String input=sc.nextLine();

        char[] charArray=input.toCharArray();
        Arrays.sort(charArray);

        String sorted=new String(charArray);

        System.out.println("Original String: "+ input);
        System.out.println("Sorted Alphabetically: "+ sorted);
    }
}