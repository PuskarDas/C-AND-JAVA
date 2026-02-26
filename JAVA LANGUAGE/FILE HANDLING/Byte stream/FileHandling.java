import java.io.*;
public class FileHandling {
    
    public void Create() throws IOException, FileNotFoundException {
        DataInputStream ob=new DataInputStream(System.in);
        FileOutputStream f=new FileOutputStream("abc.txt",true);
        System.out.println("Enter text($ to stop): ");
        int ch;
        while((ch=ob.read())!=-1) {
            if((char)ch=='$')
                break;
            f.write(ch);
        }
        f.close();
        ob.close();
    }

    public void Read() throws IOException, FileNotFoundException {
        FileInputStream fin=new FileInputStream("abc.txt");
        int i;
        do{
            i=fin.read();
            if(i!=-1)
                System.out.print((char)i);
        } while(i!=-1);
        fin.close();
    }

    public static void main(String[] args) throws IOException, FileNotFoundException {
        FileHandling ob=new FileHandling();
        ob.Create();
        ob.Read();
    }
}