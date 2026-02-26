import java.util.*;
public class longestword {
    public static void main(String[] args) {
        String st=new String();
        String word=new String();
        String maxword=new String();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your string: ");
        st=sc.nextLine();
        st=st+" ";
        
        for(int i=0;i<st.length();i++)
        {
            char ch=st.charAt(i);
            if(ch!=' ')
                word=word+ch;
            else
            {
                if(word.length()>maxword.length())
                {
                    maxword=word;
                }
                word="";
            }
        }
        System.out.println("Longest word: "+ maxword);
    }
}
