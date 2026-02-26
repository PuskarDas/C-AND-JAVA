public class Example {
    public static void main(String[] args) {
        try {
            // Code that might generate an exception
            int divideByZero = 5 / 0;
            System.out.println("This line will not execute");
        } catch (ArithmeticException e) {
            // Code to handle the exception
            System.out.println("ArithmeticException => " + e.getMessage());
        } finally {
            // Code that always executes
            System.out.println("This is the finally block, used for cleanup.");
        }
    }
}