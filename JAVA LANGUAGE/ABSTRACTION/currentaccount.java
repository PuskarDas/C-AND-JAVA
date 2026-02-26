class currentaccount extends bankaccount
{
    final double minbal=0;
    @Override void deposit(double amount)
    {
        balance+=amount;
        System.out.println("Balance: "+ balance);
    }
    
    @Override void withdraw(double amount)
    {
        if((balance-amount)<minbal)
            System.out.println("Insufficient balance");
        else
        {   
            balance-=amount;
            System.out.println("Balance after withdraw: "+ balance);
        }
    }

    public static void main(String[] args)   
    {    
        currentaccount account = new currentaccount();
        account.deposit(10000);   
        account.withdraw(12000);  
    }    
}
