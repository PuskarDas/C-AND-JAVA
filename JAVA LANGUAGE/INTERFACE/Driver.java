public class Driver {
    public static void main(String[] args) {
        Transaction ob1=new HDFC();
        ob1.deposit(1000);
        ob1.withdraw(500);

        Transaction ob2=new ICICI();
        ob2.deposit(2000);
        ob2.withdraw(6000);
    }
}
