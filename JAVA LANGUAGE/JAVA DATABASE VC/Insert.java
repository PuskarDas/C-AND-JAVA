import java.sql.*;
import java.util.Scanner;
class Insert {
    public static void main(String[] args) {
        String url="jdbc:oracle:thin:@PUSKAR:1521:xe";
        String user="Puskar";
        String password="2165";

        String insertSql="INSERT INTO student1(name, roll, class) VALUES (?, ?, ?)";
        try {
            Connection con=DriverManager.getConnection (url,user,password);
            con.setAutoCommit(false); // manage transaction manually

            Scanner sc=new Scanner(System.in);
            System.out.print("Enter name: ");
            String name=sc.nextLine().trim();

            System.out.print("Enter roll no: ");
            int roll=Integer.parseInt(sc.nextLine().trim());

            System.out.print("Enter class: ");
            String cls=sc.nextLine().trim();

            try(PreparedStatement ps=con.prepareStatement(insertSql)) {
                ps.setString(1, name);
                ps.setInt(2, roll);
                ps.setString(3, cls);
                
                int rows=ps.executeUpdate();
                if(rows==1) {
                    con.commit();
                    System.out.println("Inserted successfully.");
                } else {
                    con.rollback();
                    System.out.println("Insertion failed, rolled back.");
                }
            } catch(SQLException e) {
                con.rollback();
                System.err.println("Insert error, rolled back: "+ e.getMessage());
                e.printStackTrace();
            }
        } catch(SQLException e) {
            System.err.println("DB connection error: "+ e.getMessage());
            e.printStackTrace();
        }
    }
}