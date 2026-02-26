import java.util.*;
public class OrderOfWords {
    public static void main(String[] args) {
        String st=new String();
        String word=new String();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your string: ");
        st=sc.nextLine();
        st=st+" ";

        System.out.println("Words in Ascending order: ");
        for(int i=1;i<=st.length();i++)
        {
            for(int j=0;j<st.length();j++)
            {
                char ch=st.charAt(j);
                if(ch!=' ')                                                                       
                    word=word+ch;
                else
                {
                    if(word.length()==i)
                    {
                        System.out.println(" "+ word);;
                    }
                    word="";
                }
            }
        }

        System.out.println("Words in Descending order: ");
        for(int i=st.length();i>=1;i--)
        {
            for(int j=0;j<st.length();j++)
            {
                char ch=st.charAt(j);
                if(ch!=' ')                                                                       
                    word=word+ch;
                else
                {
                    if(word.length()==i)
                    {
                        System.out.println(" "+ word);;
                    }
                    word="";
                }
            }
        }
    }
}
