import java.sql.*;
class Read {
    public static void main(String[] args) {
        String url="jdbc:oracle:thin:@PUSKAR:1521:xe";
        String user="Puskar";
        String password="2165";
        
        PreparedStatement p=null;
        ResultSet rs=null;
        try {
            Connection con=DriverManager.getConnection(url,user,password);
            String sql="select * from student1 where class=10 AND roll>2000";
            p=con.prepareStatement(sql);
            rs=p.executeQuery();
            System.out.println("name\t\troll no\t\tclass");
            while(rs.next()) {
                    String name=rs.getString("name");
                    int roll=rs.getInt("roll");
                    String cls=rs.getString("class");
                    System.out.println(name + "\t\t" + roll + "\t\t" + cls);
                }
        } catch(SQLException e) {
            System.out.println(e);
        }
    }
}