import java.util.*;
public class Subsequence 
{
    int n=0;
    int a[];
    int maxstart=0, maxend=0, maxsize=0;
    Scanner sc = new Scanner(System.in);
    public void input()
    {
        System.out.println("Enter the number of elements: ");
        n=sc.nextInt();
        a=new int[n];

        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the number: ");
            a[i]=sc.nextInt();
        }
    }  

    public void LongestIncSubsequence() 
    {
        for(int i=0;i<=n;i++)
        {
            int start=i, end=i, size=1;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>a[j-1])
                {
                    end=j;
                    size++;
                }
                else
                {
                    if(size>maxsize)
                    {
                        maxsize=size;
                        maxend=end;
                        maxstart=start;
                    }
                    break;
                }
            }
        }
    }

    public void LongestDecSubsequence() 
    {
        for(int i=0;i<=n;i++)
        {
            int start=i, end=i, size=1;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]<a[j-1])
                {
                    end=j;
                    size++;
                }
                else
                {
                    if(size>maxsize)
                    {
                        maxsize=size;
                        maxend=end;
                        maxstart=start;
                    }
                    break;
                }
            }
        }
    }

    public void display1()
    {
        System.out.println("Largest Increasing Subsequence:-");
        for(int i=maxstart;i<=maxend;i++)
        {
            System.out.print(a[i]+",");
        }
    }

    public void display2()
    {
        System.out.println("Largest Decreasing Subsequence:-");
        for(int i=maxstart;i<=maxend;i++)
        {
            System.out.print(a[i]+",");
        }
    }

    public static void main(String[] args) {
        Subsequence s=new Subsequence();

        s.input();
        s.LongestDecSubsequence();
        s.display2();
    }
}