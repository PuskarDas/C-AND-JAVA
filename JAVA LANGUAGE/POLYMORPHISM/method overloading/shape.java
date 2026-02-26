import java.util.*;
public class shape
{
    public void area(double r)     //area of circle
    {
        double area= Math.PI*r*r;
        System.out.println("Area of circle: "+ area);
    }

    public void area(double l,double b) //area of rectangle
    {
        double area=l*b;
        System.out.println("Area of rectangle: "+ area);  
    }

    public void area(float s)      //area of square
    {
        double area=s*s;
        System.out.println("Area of square: "+ area);  
    }

    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the radius of circle: ");
        double r=sc.nextDouble();
        System.out.println("Enter the length of rectangle: ");
        double l=sc.nextDouble();
        System.out.println("Enter the breadth of rectangle: ");
        double b=sc.nextDouble();
        System.out.println("Enter the side of square: ");
        float s=sc.nextFloat();
        
        shape obj=new shape();
        obj.area(r);
        obj.area(l,b);
        obj.area(s);
    }
}
