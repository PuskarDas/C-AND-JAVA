import java.io.*;
public class BinaryFileRead {
    public static void main(String args[])
    {
        boolean bo;
        byte byt;
        char ch;
        short sh;
        int it;
        long lg;
        float ft;
        double db;

        String str;
        File f=new File("delta.txt");
        FileInputStream fis=null;
        DataInputStream dis=null;

        try {
            fis=new FileInputStream(f);
            dis=new DataInputStream(fis);
            bo=dis.readBoolean();
            byt=dis.readByte();
            ch=dis.readChar();
            sh=dis.readShort();
            it=dis.readInt();
            lg=dis.readLong();
            ft=dis.readFloat();
            db=dis.readDouble();
            str=dis.readUTF();

            System.out.println("Boolean data: "+ bo);
            System.out.println("Byte data: "+ byt);
            System.out.println("Char data: "+ ch);
            System.out.println("Short value: "+ sh);
            System.out.println("Int data: "+ it);
            System.out.println("Long data: "+ lg);
            System.out.println("Float data: "+ ft);
            System.out.println("Double data: "+ db);
            System.out.println("String data: "+ str);
        }
        catch(IOException e) {
            System.out.println(e.getMessage());
        }
        finally {
            try {
                fis.close();
                dis.close();
            } catch(IOException e) {}
        }
    }
}