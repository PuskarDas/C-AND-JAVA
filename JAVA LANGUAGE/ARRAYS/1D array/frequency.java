import java.util.*;
public class frequency 
{
    int n=0;
    int a[];

    public void input()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements: ");
        n=sc.nextInt();
        a=new int[n];

        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the number: ");
            a[i]=sc.nextInt();
        }
    }  

    public void Frequency()
    {
        for(int i=0;i<n;i++)
        {
            int c=1;
            for(int j=i+1;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    c++;
                    a[j]=0;
                }
            }
            System.out.println("Occurence of "+ a[i] +" is "+ c);
        }
    }

    public static void main(String[] args) 
    {
        frequency f1=new frequency();

        f1.input();
        f1.Frequency();
    }
}
