import java.util.*;
public class Biggest 
{
    int a[]=new int[10];
    int bigpos=0;

    public void input()
    {
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<10;i++)
        {
            System.out.println("Enter the nmuber: ");
            a[i]=sc.nextInt();
        }
    }

    public void calculate()
    {
        int big=a[0];
        for(int i=1;i<10;i++)
        {
            if(a[i]>big)
            {
                big=a[i];
                bigpos=i;
            }
        }
    }

    public void display()
    {
        System.out.println("Biggest number position: "+ bigpos);
    }

    public static void main(String[] args) 
    {
        Biggest obj=new Biggest();
        obj.input();
        obj.calculate();
        obj.display();    
    }
}
