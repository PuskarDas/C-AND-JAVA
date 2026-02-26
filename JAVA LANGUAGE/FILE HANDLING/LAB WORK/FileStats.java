import java.io.*;
import java.util.*;
public class FileStats {
    private static void displayResults(String name,int l,int w,int c) {
        System.out.println("Total Lines: "+ l);
        System.out.println("Total Words: " + w);
        System.out.println("Total Characters: "+ c);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the text file name: ");
        String fileName=sc.nextLine();
        int lineCount=0;
        int wordCount=0;
        int charCount=0;

        try (BufferedReader br=new BufferedReader(new FileReader(fileName))) {
            String line;

            while((line=br.readLine())!=null) {
                lineCount++;
                charCount+=line.length();
                String[] words=line.trim().split("\\s+");
                if(!line.trim().isEmpty()) {
                    wordCount+=words.length;
                }
            }
            displayResults(fileName,lineCount,wordCount,charCount);

        } catch(FileNotFoundException e) {
            System.err.println("was not found.");
        } catch(IOException e) {
            System.err.println("Error reading the file: "+ e.getMessage());
        } finally {
            sc.close();
        }
    }

}
