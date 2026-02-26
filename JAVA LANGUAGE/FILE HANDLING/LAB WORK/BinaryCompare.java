import java.io.*;
import java.util.*;
class BinaryCompare {
    public void compare(String path1,String path2) throws IOException, FileNotFoundException {
        FileInputStream f1=new FileInputStream(path1);
        FileInputStream f2=new FileInputStream(path2);

            long position=0;
            int byte1,byte2;
            while(true) {
                byte1=f1.read();
                byte2=f2.read();

                if(byte1==-1 && byte2==-1) {
                    System.out.println("Files are identical");
                    break;
                }
                if(byte1!=byte2) {
                    System.out.println("Files differ at byte position: " + position);
                    break;
                }
                position++;
            }
    }
    public static void main(String[] args) throws IOException, FileNotFoundException {
        Scanner sc=new Scanner(System.in);
        BinaryCompare ob=new BinaryCompare();
        System.out.print("Enter path for first file: ");
        String file1=sc.nextLine();
        System.out.print("Enter path for second file: ");
        String file2=sc.nextLine();

        ob.compare(file1,file2);
        sc.close();
    }
}