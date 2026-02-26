import java.util.*;
class HrsException extends Exception {
    public HrsException(String message){
        super(message);
    }
}
class MinException extends Exception {
    public MinException(String message){
        super(message);
    }
}
class SecException extends Exception {
    public SecException(String message){
        super(message);
    }
}

public class Time {
    static void Input() throws HrsException,MinException,SecException {
        int hours,minutes,seconds;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter hour:");
        hours=sc.nextInt();
        System.out.println("Enter minute:");
        minutes=sc.nextInt();
        System.out.println("Enter second:");
        seconds=sc.nextInt();

        if(hours<=24 && minutes<=60 && seconds<=60) {
            System.out.println("Correct time: "+ hours +":"+ minutes +":"+ seconds);
        }
        else {
            if(hours>24 || hours<0) {
                throw new HrsException("Hour is not greater than 24");
            }
            if(minutes>60 || minutes<0) {
                throw new MinException("Minute is not greater than 60");
            }
            if(seconds>60 || seconds<0) {
                throw new SecException("Second is not greater than 60");
            }
        }
    }  
    public static void main(String[] args) {
        try {
            Input();
        } 
        catch(HrsException h) {
            System.out.println("Exception caught: " + h.getMessage());
        }
        catch(MinException m) {
            System.out.println("Exception caught: " + m.getMessage());
        }
        catch(SecException s) {
            System.out.println("Exception caught: " + s.getMessage());
        }
    }
}

