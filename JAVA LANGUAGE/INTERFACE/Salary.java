import java.util.*;
class Salary{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter basic salary of Substaff: ");
        double basic=sc.nextDouble();

        Substaff s=new Substaff();

        System.out.println("Earnings: " + s.earnings(basic));
        System.out.println("Deductions: " + s.deductions(basic));
        System.out.println("Bonus: " + s.bonus(basic));
    }
}