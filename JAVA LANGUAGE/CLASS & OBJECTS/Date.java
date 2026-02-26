import java.util.*;
public class Date 
{
    int day;
    int month;
    int year;

    public Date()
    {
        day=0;
        month=0;
        year=0;
    }
    Scanner sc=new Scanner(System.in);

    void input()
    {
        System.out.println("Enter the day:");
        day=sc.nextInt();

        System.out.println("Enter the month:");
        month=sc.nextInt();

        System.out.println("Enter the year:");
        year=sc.nextInt();
    }

    public static Date datedifference(Date d1, Date d2)
    {
        Date d=new Date();

        if(d1.day<d2.day)
        {
            d1.month--;
            d1.day+=30;
        }
        d.day=d1.day-d2.day;

        if(d1.month<d2.month)
        {
            d1.year--;
            d1.month+=12;
        }
        d.month=d1.month-d2.month;
        
        d.year=d1.year-d2.year;
        return d;
    }

    void display()
    {
        System.out.println(" Day "+ day+ " Month "+ month+ " Year "+year);
    }

    public static void main(String args[]) 
    {
        Date today=new Date();
        Date dob=new Date();
        Date age=new Date();
        
        System.out.println("Enter today's date:-");
        today.input();

        System.out.println("Enter date of birth:-");
        dob.input();

        age=datedifference(today, dob);
        age.display();
    }
}