import java.util.*;
public class box extends Plate
{
    double h;
    
    public box()
    {
        super();         //calling parent class constructor 
        h=0.0;
    }

    public box(double p, double q, double r)
    {
        super(p,q);
        h=r;
    }
    Scanner sc=new Scanner(System.in);
    void input()
    {
        super.input();
        System.out.println("Enter the height:");
        h=sc.nextDouble();
    }

    void display()
    {
        super.display();
        System.out.println("Height:"+h);
    }

    public static void main(String[] args) 
    {
        box d=new box();

        d.input();
        d.display();
    }
}

