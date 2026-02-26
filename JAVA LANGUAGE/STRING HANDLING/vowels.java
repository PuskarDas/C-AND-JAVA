import java.util.*;
public class vowels {
    public static void main(String[] args) {
        String st=new String();
        int vowel=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your string: ");
        st=sc.nextLine();

        for(int i=0;i<st.length();i++)
        {
            char ch=st.charAt(i);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            {
                vowel++;
            }    
        }
        System.out.println("No.of vowels: "+ vowel);
    }
}