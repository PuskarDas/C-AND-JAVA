public class ICICI implements Transaction{
    double balance=3000;
    double amount;
    public void deposit(double amount)
    {
        balance+=amount;
        System.out.println("Balance: "+ balance);
    }
    public void withdraw(double amount) 
    {
        if(amount<=balance)
        {
            balance=balance-amount;
            System.out.println("Remaining balance: "+ balance);
        }
        else
        {
            System.out.println("Insuffcient funds");
        }
    }
}
