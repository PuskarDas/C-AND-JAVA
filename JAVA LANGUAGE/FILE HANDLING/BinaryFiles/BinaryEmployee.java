import java.io.*;
import java.util.*;
public class BinaryEmployee {
    public void AddEmployee() {
        int empcode=0;
        double salary=0.0;
        String empname="";
        File f=new File("Employee.txt");
        FileOutputStream fos=null;
        DataOutputStream dos=null;
        Scanner sc=new Scanner(System.in);
        try {
            fos=new FileOutputStream(f,true);
            dos=new DataOutputStream(fos);
            System.out.println("Enter Employee name: ");
            empname=sc.nextLine();
            System.out.println("Enter Employee code: ");
            empcode=sc.nextInt();
            System.out.println("Enter Employee salary: ");
            salary=sc.nextDouble();

            dos.writeUTF(empname);
            dos.writeInt(empcode);
            dos.writeDouble(salary);
        } catch(IOException e) {
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
    
    public void ReadEmployee() {
        int empcode=0;
        double salary=0.0;
        String empname="";

        File f=new File("Employee.txt");
        FileInputStream fis=null;
        DataInputStream dis=null;

        try {
            fis=new FileInputStream(f);
            dis=new DataInputStream(fis);
            
            while((empname=dis.readUTF())!=null)
            {
                empcode=dis.readInt();
                salary=dis.readDouble();
                System.out.println("Employee name is  "+ empname);
                System.out.println("Employee code is "+ empcode);
                System.out.println("Salary is "+ salary);
            }
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
        finally {
            try {
                fis.close();
                dis.close();
            } catch(IOException e) {}
        }
    }

    public void SearchEmployee() {
        int empcode=0;
        double salary=0.0;
        String empname="";

        File f=new File("Employee.txt");
        FileInputStream fis=null;
        DataInputStream dis=null;
        Scanner sc=new Scanner(System.in);

        int found=0;
        System.out.println("Enter empcode to search: ");
        int ecode=sc.nextInt();

        try {
            fis=new FileInputStream(f);
            dis=new DataInputStream(fis);
            
            while((empname=dis.readUTF())!=null)
            {
                //empname=dis.readUTF();
                empcode=dis.readInt();
                salary=dis.readDouble();
                if(ecode==empcode) {
                    System.out.println("Employee name is  "+empname);
                    System.out.println("Employee code is "+empcode);
                    System.out.println("Salary is "+salary);
                    found=1;
                }
            }
        } catch(IOException e) {
            System.out.println(e.getMessage());
            if(found==0)
                System.out.println("Employee Code not found");
        }
        finally {
            try {
                fis.close();
                dis.close();
            } catch(IOException e) {}
        }
    }

    public void DeleteEmployee() {
        int empcode=0;
        double salary=0.0;
        String empname="";

        File f=new File("Employee.txt");
        File f1=new File("temp.txt");
        FileInputStream fis=null;
        DataInputStream dis=null;

        FileOutputStream fos=null;
        DataOutputStream dos=null;
        Scanner sc=new Scanner(System.in);

        int found=0;
        System.out.println("Enter empcode to delete: ");
        int ecode=sc.nextInt();

        try {
            fis=new FileInputStream(f);
            dis=new DataInputStream(fis);

            fos=new FileOutputStream(f1);
            dos=new DataOutputStream(fos);
            
            while((empname=dis.readUTF())!=null)
            {
                //empname=dis.readUTF();
                empcode=dis.readInt();
                salary=dis.readDouble();
                if(ecode!=empcode) {
                    dos.writeUTF(empname);
                    dos.writeInt(empcode);
                    dos.writeDouble(salary);
                }
                else { found=1; }
            }
        } catch(IOException e) {
            System.out.println(e.getMessage());
            if(found==0)
                System.out.println("Employee Code not found");
        }
        finally {
            try {
                fis.close();
                dis.close();
                fos.close();
                dos.close();
                f.delete();
                f1.renameTo(f);
            } catch(IOException e) {}
        }
    }
    public static void main(String[] args) {
        BinaryEmployee ob=new BinaryEmployee();
        //ob.AddEmployee();
        ob.AddEmployee();
        ob.AddEmployee();
        ob.ReadEmployee();
        //ob.SearchEmployee();
        //ob.DeleteEmployee();
    }
}