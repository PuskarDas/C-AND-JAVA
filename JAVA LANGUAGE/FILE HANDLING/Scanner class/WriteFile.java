import java.io.FileWriter;
import java.io.IOException; 

public class WriteFile 
{
    public static void main(String[] args)
    {
        // Writing Text File       
        try {

            FileWriter Writer = new FileWriter("myfile.txt");

            // Writing File
            Writer.write("Files in Java are seriously good!!");
            Writer.write("\nWe are learning File Handling");
            Writer.close();
            
            System.out.println("Successfully written.");
        }

        // Exception Thrown
        catch (IOException e) {
            System.out.println("An error has occurred.");
            e.printStackTrace();
        }
    }
}
