import java.util.*; 
public class Shift 
{
    int n=0,k=0;
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

    public void RightShift()
    {
        System.out.println("Enter kth element to reverse: ");
        k=sc.nextInt();
        for(int i=1;i<=k;i++)
        {
            int temp=a[n-1];
            for(int j=n-1;j>0;j--)
                a[j]=a[j-1];
            a[0]=temp;
        }
    }

    public void LeftShift()
    {
        for(int i=1;i<=k;i++)
        {
            int temp=a[0];
            for(int j=0;j<=n-2;j++)
                a[j]=a[j+1];
            a[n-1]=temp;
        }
    }

    public void AlternateRightShift()
    {
        //System.out.println("Enter kth element to reverse: ");
        //k=sc.nextInt();
        for(int i=1;i<=k;i++)
        {
            int temp1=a[n-1];
            int temp2=a[n-2];
            for(int j=n-1;j>1;j--)
                a[j]=a[j-2];
            a[1]=temp1;
            a[0]=temp2;
        }
    }

    public void AlternateLeftShift()
    {
        System.out.println("Enter kth element to reverse: ");
        k=sc.nextInt();
        for(int i=1;i<=k;i++)
        {
            int temp1=a[1];
            int temp2=a[0];
            for(int j=0;j<=n-3;j++)
                a[j]=a[j+2];
            a[n-1]=temp1;
            a[n-2]=temp2;
        }
    }

    public void display1()
    {
        System.out.println("Array after Right shift: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+",");
        }
    }

    public void display2()
    {
        System.out.println("Array after Left shift: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+",");
        }
    }

    public void display3()
    {
        System.out.println("Array after Alternate Right shift: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+",");
        }
    }

    public void display4()
    {
        System.out.println("Array after Alternate Left shift: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+",");
        }
    }
    public static void main(String []args) 
    {
        Shift s = new Shift();

        s.input();
        /*s.RightShift();
        s.display1();
        System.out.println("");
        s.LeftShift();
        s.LeftShift();
        s.display2();
        System.out.println("");
        s.RightAlternateShift();
        s.RightAlternateShift();
        s.display3();
        System.out.println("");
        s.LeftAlternateShift();*/
        s.AlternateLeftShift();
        s.display4();
    }
}