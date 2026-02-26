import java.util.*;
public class Bankaccount 
{
    int accnum;
    String name;
    double balance,amount;

    Scanner sc=new Scanner(System.in);
    Scanner sc2=new Scanner(System.in);

    public void input()
    {
        System.out.println("Enter account number");
        accnum=sc.nextInt();

        System.out.println("Enter Customer name");
        name=sc2.nextLine();

        System.out.println("Enter Opening Balance");
        balance=sc.nextDouble();
    }

    public void deposit()
    {
        System.out.println("Enter amount to deposit");
        amount=sc.nextDouble();

        balance=balance+amount;

    }

    public void withdraw()
    {
        System.out.println("Enter amount to withdraw");
        amount=sc.nextDouble();

        if(amount<balance)
            balance=balance-amount;
        else
            System.out.println("Insufficient Balance");
    }

    public void Display()
    {
        System.out.println("Account Number "+ accnum);
        System.out.println("Customer name "+ name);
        System.out.println("Net Balance "+ balance);
    }

    public static void main(String[] args)
    {
        Bankaccount b1=new Bankaccount();
        
        b1.input();
        b1.deposit();
        b1.withdraw();
        b1.Display();
    }
}

