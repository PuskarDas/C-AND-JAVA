import java.util.*;
import java.io.*;
public class FileHandling3 {
     public void Create() throws IOException, FileNotFoundException {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter text: ");
        String str=sc.nextLine();
        FileWriter fw=new FileWriter("abc.txt",true);
        BufferedWriter buf=new BufferedWriter(fw);
        buf.write(str);
        buf.close();
        fw.close();
    }

    public void Read() throws IOException, FileNotFoundException {
        FileReader fr=new FileReader("abc.txt");
        BufferedReader buf=new BufferedReader(fr);
        int i;
        while((i=buf.read())!=-1){
            System.out.print((char)i);
        }
        buf.close(); 
        fr.close();
    }
    public static void main(String[] args) throws IOException, FileNotFoundException {
        FileHandling3 ob=new FileHandling3();
        ob.Create();
        ob.Read();
    }
}