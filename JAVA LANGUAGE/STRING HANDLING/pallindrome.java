import java.util.*;
public class pallindrome {
    public static void main(String[] args) {
        String st=new String();
        String rev=new String();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your string: ");
        st=sc.nextLine();

        for(int i=0;i<st.length();i++)
        {
            char ch=st.charAt(i);
            rev=ch+rev;
        }
        if(st.equalsIgnoreCase(rev))
            System.out.println(st +" is a pallindrome");
        else
            System.out.println(st +" is not a pallindrome");
    }
}
