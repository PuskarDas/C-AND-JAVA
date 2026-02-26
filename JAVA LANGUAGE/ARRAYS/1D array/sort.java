import java.util.*;
public class sort
{
    int n=0;
    int a[];
    int bigpos=0;

    public void input()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the nmuber of elements: ");
        n=sc.nextInt();
        a=new int[n];

        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the nmuber: ");
            a[i]=sc.nextInt();
        }
    }

    public void BubbleSort()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }
    
    public void display()
    {
        System.out.println("Sorted in ascending order: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+",");
        }
    }

    public static void main(String[] args) 
    {
        sort sr = new sort();

        sr.input();
        sr.BubbleSort();
        sr.display();
    }
}
