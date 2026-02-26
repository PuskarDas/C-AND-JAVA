import java.io.*;
public class Test {
    public static void main(String []args) throws IOException, FileNotFoundException {
        FileInputStream fin=new FileInputStream("abc.txt");
        FileOutputStream fout=new FileOutputStream("xyz.txt");
        int i;
        do {
            i=fin.read();
            if(i!=-1)
                fout.write(i);
        } while(i!=-1);
        fin.close();
        fout.close();
    }
}