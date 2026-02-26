import java.util.*;                                                               
import java.io.*;                                 
public class Student2 {
     public void Create() throws IOException, FileNotFoundException {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter roll no: ");
        String roll=sc.nextLine();
        System.out.println("Enter name: ");
        String name=sc.nextLine();
        System.out.println("Enter Subject: ");
        String subject=sc.nextLine();
        System.out.println("Enter marks: ");
        String marks=sc.nextLine();
        FileWriter fw=new FileWriter("abc.txt");
        for(int i=0;i<roll.length();i++)
            fw.write(roll.charAt(i));
        for(int i=0;i<name.length();i++)
            fw.write(name.charAt(i));
        for(int i=0;i<subject.length();i++)
            fw.write(subject.charAt(i));
        for(int i=0;i<marks.length();i++)
            fw.write(marks.charAt(i));
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
        Student2 ob=new Student2();
        ob.Create();
        ob.Read();
    }

}