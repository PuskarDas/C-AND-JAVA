import java.sql.*;
import java.util.Scanner;
public class LibraryProject {
    static final String DB_URL="jdbc:oracle:thin:@PUSKAR:1521:xe";
    static final String USER="Puskar"; 
    static final String PASS="2165";
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(true) {
            System.out.println("\n--- LIBRARY MANAGEMENT SYSTEM ---");
            System.out.println("1. Register Student");
            System.out.println("2. Add New Book");
            System.out.println("3. Issue a Book");
            System.out.println("4. Return a Book");
            System.out.println("5. View Inventory");
            System.out.println("6. Exit");
            System.out.print("Select an option: ");
            int choice=sc.nextInt();
            sc.nextLine();
            switch(choice) {
                case 1:
                    System.out.print("Enter Name: "); String name=sc.nextLine();
                    System.out.print("Enter Email: "); String email=sc.nextLine();
                    insertStudent(name,email);
                    break;
                case 2:
                    System.out.print("Enter Title: "); String title=sc.nextLine();
                    System.out.print("Enter Author: "); String author=sc.nextLine();
                    insertBook(title, author);
                    break;
                case 3:
                    System.out.print("Enter Book ID: "); int bId=sc.nextInt();
                    System.out.print("Enter Student ID: "); int sId=sc.nextInt();
                    Issue(bId, sId);
                    break;
                case 4:
                    System.out.print("Enter Book ID to return: "); int rId=sc.nextInt();
                    ReturnBook(rId);
                    break;
                case 5:
                    showBook();
                    break;
                case 6:
                    System.out.println("Closing System...");
                    System.exit(0);
                default:
                    System.out.println("Invalid Selection!");
            }
        }
    }
    private static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(DB_URL,USER,PASS);
    }
    public static void insertStudent(String name, String email) {
        String sql="INSERT INTO students (name, email) VALUES (?, ?)";
        try {
            Connection conn=getConnection(); 
            PreparedStatement ps=conn.prepareStatement(sql);
            ps.setString(1,name);
            ps.setString(2,email);
            ps.executeUpdate();
            System.out.println("Student registered successfully.");
        } catch(SQLException e) { 
            System.out.println("Error: "+ e.getMessage()); 
        }
    }
    public static void insertBook(String title, String author) {
        String sql="INSERT INTO books (title, author) VALUES (?, ?)";
        try {
            Connection conn=getConnection(); 
            PreparedStatement ps=conn.prepareStatement(sql);
            ps.setString(1, title);
            ps.setString(2, author);
            ps.executeUpdate();
            System.out.println("Book added to library.");
        } catch(SQLException e) { 
            System.out.println("Error: "+ e.getMessage()); 
        }
    }
    public static void Issue(int bookId,int studentId) {
        String logSql="INSERT INTO issue_log (book_id, student_id) VALUES (?, ?)";
        String updateSql="UPDATE books SET status = 'ISSUED' WHERE book_id = ? AND status = 'AVAILABLE'";
        try {
            Connection conn=getConnection();
            conn.setAutoCommit(false);
            try {
                PreparedStatement psUpdate=conn.prepareStatement(updateSql);
                PreparedStatement psLog=conn.prepareStatement(logSql);
                psUpdate.setInt(1,bookId);
                int rows=psUpdate.executeUpdate();
                if(rows>0) {
                    psLog.setInt(1, bookId);
                    psLog.setInt(2, studentId);
                    psLog.executeUpdate();
                    conn.commit();
                    System.out.println("Book issued successfully.");
                } else {
                    System.out.println("Book is not available or ID is wrong.");
                    conn.rollback();
                }
            }
            finally{}
        } catch(SQLException e) { 
            System.out.println("Transaction Failed: "+ e.getMessage()); 
        }
    }
    public static void ReturnBook(int bookId) {
        String updateLog="UPDATE issue_log SET return_date = SYSDATE WHERE book_id = ? AND return_date IS NULL";
        String updateBook="UPDATE books SET status = 'AVAILABLE' WHERE book_id = ?";
        try {
            Connection conn=getConnection();
            conn.setAutoCommit(false);
            try {
                PreparedStatement ps1=conn.prepareStatement(updateLog);
                PreparedStatement ps2=conn.prepareStatement(updateBook);
                ps1.setInt(1, bookId);
                ps1.executeUpdate();
                
                ps2.setInt(1, bookId);
                ps2.executeUpdate();
                
                conn.commit();
                System.out.println("Book returned");
            }
            finally{}
        } catch(SQLException e) { 
            System.out.println("Error: "+ e.getMessage()); 
        }
    }
    public static void showBook() {
        String sql="SELECT * FROM books ORDER BY book_id";
        try {
            Connection conn=getConnection(); 
            Statement st=conn.createStatement(); 
            ResultSet rs=st.executeQuery(sql);
            System.out.println("\nID\tTITLE\t\t\tAUTHOR\t\tSTATUS");
            while(rs.next()) {
                System.out.println(rs.getInt("book_id") + "\t" + rs.getString("title") + "\t\t" + rs.getString("author") + "\t\t" + rs.getString("status"));
            }
        } catch(SQLException e) { 
            System.out.println("Error: "+ e.getMessage()); 
        }
    }
}