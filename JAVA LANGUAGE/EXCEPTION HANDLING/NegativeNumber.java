import java.util.Scanner;
public class NegativeNumber {
    static void ProcessInput() throws NegativeNumberException {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number: ");
        int a=sc.nextInt();

        if(a>=0){
            int b=a*2;
            System.out.println("Double value: "+ b);
        }
        else{
            throw new NegativeNumberException("Number must be positive");
        }
    }
    public static void main(String[] args) 
    {
        try {
            ProcessInput();
        } 
        catch(NegativeNumberException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}

class NegativeNumberException extends Exception {
    public NegativeNumberException(String message){
        super(message);
    }
}
