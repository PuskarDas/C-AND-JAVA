class HDFC implements Transaction {
    double balance=5000;
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
