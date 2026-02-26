import java.util.*;
public class Merge {
    public static String mergeBetween(String s1,String s2) {
        StringBuilder result=new StringBuilder();
        int i=0;
        while (i<s1.length() || i<s2.length()) {
            if (i<s1.length()) {
                result.append(s1.charAt(i));
            }
            if (i<s2.length()) {
                result.append(s2.charAt(i));
            }
            i++;
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter first string: ");
        String str1=sc.nextLine();

        System.out.print("Enter second string: ");
        String str2=sc.nextLine();

        String combined=str1+str2;
        System.out.println("Simple Concatenation: "+ combined);

        String interleaved=mergeBetween(str1,str2);
        System.out.println("Interleaved Merge: "+ interleaved);
    }
}
