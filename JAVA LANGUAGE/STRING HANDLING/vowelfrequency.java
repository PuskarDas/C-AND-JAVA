import java.util.*;
public class vowelfrequency {
    public static void main(String[] args) {
        String st=new String();
        int na=0,ne=0,ni=0,no=0,nu=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your string: ");
        st=sc.nextLine();

        for(int i=0;i<st.length();i++)
        {
            char ch=st.charAt(i);
            if(ch=='a' || ch=='A')
                na++;  
            if(ch=='e' || ch=='E')
                ne++;
            if(ch=='i' || ch=='I')
                ni++;
            if(ch=='o' || ch=='O')
                no++;   
            if(ch=='u' || ch=='U')
                nu++;  
        }
        System.out.println("No.of a: "+ na);
        System.out.println("No.of e: "+ ne);
        System.out.println("No.of i: "+ ni);
        System.out.println("No.of o: "+ no);
        System.out.println("No.of u: "+ nu);
    }
}
