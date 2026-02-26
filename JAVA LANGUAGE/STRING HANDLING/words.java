import java.util.*;
public class words {
    public static void main(String[] args) {
        String st=new String();
        int word=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your string: ");
        st=sc.nextLine();

        for(int i=0;i<st.length()-1;i++)
        {
            char ch=st.charAt(i);
            char ch2=st.charAt(i+1);
            if(ch==' ' && ch2!=' ')
            {
                word++;
            }    
        }
        System.out.println("No.of words: "+ (word+1));
    }
}
