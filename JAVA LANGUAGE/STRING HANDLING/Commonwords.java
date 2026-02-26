import java.util.*;
public class Commonwords {                
    public static void main(String[] args) 
    {
        String st1=new String();
        String st2=new String();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter 1st string: ");
        st1=sc.nextLine();
        //String word1=st1.split();
        String word1=new String();
        st1=st1+" ";
        System.out.println("Enter 2nd string: ");
        st2=sc.nextLine();
        //String word2=st2.split();
        String word2=new String();
        st2=st2+" ";  

        for(int i=0;i<st1.length();i++)
        {
            char ch1=st1.charAt(i);
            if(ch1!=' ')                                                                       
                    word1=word1+ch1;
            else 
            {   
                for(int j=0;j<st2.length();j++)
                {
                    char ch2=st2.charAt(j);
                    if(ch2!=' ')                                                                       
                        word2=word2+ch2; 
                    else
                    {
                        if(word1.equals(word2))
                        {
                            System.out.println("Common word: "+ word1);
                        }
                        word2="";
                    }   
                }
                word1="";
            }
        }
    }
}
