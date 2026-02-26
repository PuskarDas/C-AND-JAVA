import java.io.*;
public class BinaryFileWrite { 
    public static void main(String args[]) {
        boolean bo=true;
        byte byt=12;
        char ch='A';
        short sh=256;
        int it=5862;
        long lg=458671;
        float ft=78.214f;
        double db=2458.325;

        String str="Hello Java";
        File f=new File("delta.txt");
        FileOutputStream fos=null;
        DataOutputStream dos=null;

        try {
            fos=new FileOutputStream(f);
            dos=new DataOutputStream(fos);
            dos.writeBoolean(bo);
            dos.writeByte(byt);
            dos.writeChar(ch);
            dos.writeShort(sh);
            dos.writeInt(it);
            dos.writeLong(lg);
            dos.writeFloat(ft);
            dos.writeDouble(db);
            dos.writeUTF(str);
        }
        catch(IOException e) {
            System.out.println(e.getMessage());
        }
        finally {
            try {
                fos.close();
                dos.close();
            }
            catch(IOException e) {}
        }
    }
}