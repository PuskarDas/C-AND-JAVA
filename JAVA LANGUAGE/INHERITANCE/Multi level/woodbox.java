import java.util.*;
public class woodbox extends box
{
    double t;
    
    public woodbox()
    {
        super();         //calling parent class constructor 
        t=0.0;
    }

    public woodbox(double p, double q, double r, double s)
    {
        super(p,q,r);
        t=s;
    }
    Scanner sc=new Scanner(System.in);
    void input()
    {
        super.input();
        System.out.println("Enter the thickness:");
        t=sc.nextDouble();
    }

    void display()
    {
        super.display();
        System.out.println("Thickness:"+t);
    }

    public static void main(String[] args) 
    {
        woodbox e=new woodbox();

        e.input();
        e.display();
    }
}

