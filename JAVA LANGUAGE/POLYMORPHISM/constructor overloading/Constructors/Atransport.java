import java.util.*;
public class Atransport 
{
    String name;
    int w;
    int charge;

    public Atransport()      //non parameretised constructor
    {
        name="";
        w=0;
        charge=0;
    }

    public Atransport(String n,int w2)      //parameretised constructor
    {
        name=n;
        w=w2;
        charge=0;
    }

    Scanner sc=new Scanner(System.in);

    public void accept()
    {
        System.out.println("Enter name of the customer:");
        name=sc.nextLine();

        System.out.println("Enter weight of the parcel:");
        w=sc.nextInt();
    }

    public void calculate()
    {
        if(w<=10)
            charge=25*w;
        else if(w<=30)
            charge=20*w;
        else 
            charge=10*w;

        charge+=0.05*charge;
    }

    public void print()
    {
        System.out.println("Name :"+ name);
        System.out.println("Weight :"+ w);
        System.out.println("Total bill :"+ charge);
    }

    public static void main(String args[])
    {
        Atransport tr=new Atransport();
        Atransport tr2=new Atransport("Puskar",25);

        tr.accept();
        tr.calculate();
        tr.print();

        tr2.calculate();
        tr2.print();
    }
}
