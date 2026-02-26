import java.util.*;
public class shortestword {
    public static void main(String[] args) {
        String st=new String();
        String word=new String();
        String minword=new String();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your string: ");
        st=sc.nextLine();
        st=st+" ";
        minword=st;
        for(int i=0;i<st.length();i++)
        {
            char ch=st.charAt(i);
            if(ch!=' ')                                                                       
                word=word+ch;
            else
            {
                if(word.length()<minword.length())
                {
                    minword=word;
                }
                word="";
            }
        }
        System.out.println("Shortest word: "+ minword);
    }
}
