import java.util.*;
public class Plastic2D 
{
    double l,b,area,cost;
    
    public Plastic2D()
    {
        l=0.0;
        b=0.0;
        area=0.0;
        cost=0.0;
    }

    public Plastic2D(double p, double q)
    {
        l=p;
        b=q;
        area=0.0;
        cost=0.0;
    }

    Scanner sc=new Scanner(System.in);

    void input()
    {
        System.out.println("Enter the length:");
        l=sc.nextDouble();

        System.out.println("Enter the breadth:");
        b=sc.nextDouble();
    }

    void calculate()
    {
        area=l*b;
        cost=40*area;
    }

    void display()
    {
        System.out.println("Cost of 2D plastic:"+cost);
    }

    public static void main(String[] args) 
    {
        Plastic2D p=new Plastic2D();

        p.input();
        p.calculate();
        p.display();
    }
}
