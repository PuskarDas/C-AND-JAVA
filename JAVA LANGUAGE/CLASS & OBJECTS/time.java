import java.util.*;
public class time 
{
    int hr;
    int min;
    int s;

    public time()
    {
        hr=0;
        min=0;
        s=0;
    }
    Scanner sc = new Scanner(System.in);

    void input()
    {
        System.out.println("Enter the hour:");
        hr=sc.nextInt();

        System.out.println("Enter the minute:");
        min=sc.nextInt();

        System.out.println("Enter the second:");
        s=sc.nextInt();
    }

    public static time timedifference(time t1, time t2)
    {
        time t=new time();

        if(t1.s<t2.s)
        {
            t1.min--;
            t1.s+=60;
        }
        t.s=t1.s-t2.s;

        if(t1.min<t2.min)
        {
            t1.hr--;
            t1.min+=60;
        }
        t.min=t1.min-t2.min;

        t.hr=t1.hr-t2.hr;
        return t;
    }

    void display()
    {
        System.out.println(" Hour "+ hr+ " Minute "+ min+ " second "+s);
    }

    public static void main(String args[]) 
    {
        time curr=new time();
        time prev=new time();
        time t=new time();

        System.out.println("Enter current time:-");
        curr.input();

        System.out.println("Enter previous time:-");
        prev.input();

        t=timedifference(curr, prev);
        t.display();
    }
}
