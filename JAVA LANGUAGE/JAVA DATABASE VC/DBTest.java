import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
public class DBTest {
    public static void main(String[] args) {
        String url="jdbc:oracle:thin:@PUSKAR:1521:xe";
        String user="Puskar";
        String password="2165";

        try {
            Connection conn=DriverManager.getConnection(url,user,password);
            System.out.println("Connected to Oracle Database successfully");
            conn.close();
        } catch (SQLException e) {
            System.err.println("Connection Failed!");
            e.printStackTrace();
        }
    }
}