import java.util.*;                                                               
import java.io.*;                                 
public class FileHandling2 {
    public void Create() throws IOException, FileNotFoundException {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter text: ");
        String str=sc.nextLine();
        FileWriter fw=new FileWriter("abc.txt",true);
        for(int i=0;i<str.length();i++)
        {
            fw.write(str.charAt(i));
        }
        fw.close();
    }

    public void Read() throws IOException, FileNotFoundException {
        FileReader fr=new FileReader("abc.txt");
        int i;
        while((i=fr.read())!=-1){
            System.out.print((char)i);
        } 
        fr.close();
    }
    public static void main(String[] args) throws IOException, FileNotFoundException {
        FileHandling2 ob=new FileHandling2();
        ob.Create();
        ob.Read();
    }
}