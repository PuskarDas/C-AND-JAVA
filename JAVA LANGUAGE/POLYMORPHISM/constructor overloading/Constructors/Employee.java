import java.util.*;
class Employee
{
    int empcode;
    String empname;
    double basic,da,hra,ma,pf,net;
    
    Employee()
    {
        empcode=0;
        empname="";
        basic=0.0;
        da=0.0;
        hra=0.0;
        ma=0.0;
        pf=0.0;
        net=0.0;
    }
    
    Employee(int ecode,String ename,double b)
    {
        empcode=ecode;
        empname=ename;
        basic=b;
        da=0.0;
        hra=0.0;
        ma=0.0;
        pf=0.0;
        net=0.0;
    }
    
    public void input()
    {
        Scanner sc1 = new Scanner(System.in);
        Scanner sc2 = new Scanner(System.in);
        
        System.out.println("Enter employee code");
        empcode=sc1.nextInt();
        
        System.out.println("Enter employee name");
        empname=sc2.nextLine();
        
        System.out.println("Enter Basic salary");
        basic=sc1.nextDouble();
    }
    
    public void calculate()
    {
        da=0.85*basic;
        hra=0.35*basic;
        ma=0.25*basic;
        pf=0.125*basic;
        net=basic+da+ma+hra-pf;
    }
    
    public void Display()
    {
        System.out.println("Employee code "+ empcode);
        System.out.println("Employee name "+ empname);
        System.out.println("Net Salary "+ net);
    }
    
    public static void main(String[] args)
    {
        Employee emp1=new Employee();
        //Employee emp2=new Employee(101,"Puskar Das",25000);
        
        emp1.input();
        emp1.calculate();
        emp1.Display();
    }
}
