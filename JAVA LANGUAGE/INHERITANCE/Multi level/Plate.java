import java.util.*;
public class Plate 
{
    double l,b;
    
    public Plate()
    {
        l=0.0;
        b=0.0;
    }

    public Plate(double p, double q)
    {
        l=p;
        b=q;
    }

    Scanner sc=new Scanner(System.in);

    void input()
    {
        System.out.println("Enter the length:");
        l=sc.nextDouble();

        System.out.println("Enter the breadth:");
        b=sc.nextDouble();
    }

    void display()
    {
        System.out.println("Length:"+l);
        System.out.println("Width:"+b);
    }

    public static void main(String[] args) 
    {
        Plate p=new Plate();

        p.input();
        p.display();
    }
}

