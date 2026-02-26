import java.io.*;
import java.util.Scanner;
class Student {
    String roll,name,subject,marks;
    Scanner sc=new Scanner(System.in);
    public void Create()
    {
        try {
            File Obj=new File("Details.txt");

          	if(Obj.createNewFile()) {
                System.out.println("File created: "+ Obj.getName());
            } else {
                System.out.println("File already exists");
            }
        }

        catch(IOException e) {
            System.out.println("An error has occurred");
            e.printStackTrace();
        }
    }
    public void Write()
    {
        try {
            Scanner sc2=new Scanner(System.in);
            System.out.println("Enter Student roll no: ");
            roll=sc2.nextLine();
            System.out.println("Enter name: ");
            name=sc2.nextLine();
            System.out.println("Enter Subject: ");
            subject=sc2.nextLine();
            System.out.println("Enter marks: ");
            marks=sc2.nextLine();

            FileWriter Writer=new FileWriter("Details.txt",true);

            Writer.write(roll+"\n");
            Writer.write(name+"\n");
            Writer.write(subject+"\n");
            Writer.write(marks+"\n");
            Writer.close();
            System.out.println("Successfully written");
        }

        catch(IOException e) {
            System.out.println("An error has occurred");
            e.printStackTrace();
        }
    }
    public void Display()
    {
    try {
            File obj=new File("Details.txt");
            Scanner read=new Scanner(obj);
   
          	while(read.hasNextLine()) {
                roll=read.nextLine();
                System.out.println("Roll: "+roll);
                name=read.nextLine();
                System.out.println("Name: "+name);
                subject=read.nextLine();
                System.out.println("Subject: "+subject);
                marks=read.nextLine();
                System.out.println("marks scored: "+marks);
            }
            read.close();
        }

        catch(FileNotFoundException e) {
            System.out.println("An error has occurred");
            e.printStackTrace();
        }
    }
    public void Search()
    {
        String r; 
        int found=0; 
        System.out.println("Enter roll no. to search: ");
        r=sc.next();
        try {
            File obj=new File("Details.txt");
            Scanner read=new Scanner(obj);
   
          	while(read.hasNextLine()) {
                roll=read.nextLine();
                name=read.nextLine();
                subject=read.nextLine();
                marks=read.nextLine();
                
                if(roll.equals(r))
                {
                    System.out.println("Roll: "+roll);
                    System.out.println("Name: "+name);
                    System.out.println("Subject: "+subject);
                    System.out.println("marks scored: "+marks);
                    found=1;
                }
            }
            if(found==0)
                System.out.println("Roll no not found");
            read.close();
        }

        catch(FileNotFoundException e) {
            System.out.println("An error has occurred");
            e.printStackTrace();
        }
    }
    public static void main(String[] args)
    {
        Student obj=new Student();
        obj.Create();
        obj.Write();
        //obj.Write();
        obj.Search();
    }

}