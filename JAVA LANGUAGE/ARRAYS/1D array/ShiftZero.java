import java.util.*;
public class ShiftZero 
{
    int n=0;
    int a[];
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
    
    public void ShifttoLeft()
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                for(int j=i;j>0;j--)
                    a[j]=a[j-1];
                a[0]=0;
            }
        }
    }

    public void ShifttoRight()
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                for(int j=i;j<=n-2;j++)
                    a[j]=a[j+1];
                a[n-1]=0;
            }
        }
    }

    public void display1()
    {
        System.out.println("Array after Shifting zeroes to right: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+",");
        }
    }
    public void display2()
    {
        System.out.println("Array after Shifting zeroes to left: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+",");
        }
    }
    public static void main(String[] args) {
        ShiftZero s=new ShiftZero();

        s.input();
        s.ShifttoRight();
        s.display2();
    }
}
