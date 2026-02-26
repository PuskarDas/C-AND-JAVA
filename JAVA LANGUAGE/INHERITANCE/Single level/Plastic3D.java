import java.util.*;
public class Plastic3D extends Plastic2D
{
    double h,vol,cost;
    
    public Plastic3D()
    {
        super();         //calling parent class constructor 
        h=0.0;
        vol=0.0;
        cost=0.0;
    }

    public Plastic3D(double p, double q, double r)
    {
        super(p,q);
        h=r;
        vol=0.0;
        cost=0.0;
    }
    Scanner sc=new Scanner(System.in);
    void input()
    {
        super.input();
        System.out.println("Enter the height:");
        h=sc.nextDouble();
    }

    void calculate()
    {
        vol=super.l*super.b*h;
        cost=60*vol;
    }

    void display()
    {
        System.out.println("Cost of 3D plastic box:"+cost);
    }

    public static void main(String[] args) 
    {
        Plastic3D d=new Plastic3D();

        d.input();
        d.calculate();
        d.display();
    }

    public double getH() {
        return h;
    }

    public void setH(double h) {
        this.h = h;
    }

    public double getVol() {
        return vol;
    }

    public void setVol(double vol) {
        this.vol = vol;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    public Scanner getSc() {
        return sc;
    }

    public void setSc(Scanner sc) {
        this.sc = sc;
    }
}
