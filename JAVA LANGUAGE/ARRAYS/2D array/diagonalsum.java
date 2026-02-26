import java.util.*;
public class diagonalsum 
{
    int s1=0,s2=0;
    int a[][]=new int[3][3];
    
    public void input()
    {
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                System.out.println("Enter the elements: ");
                a[i][j]=sc.nextInt();
            }
        }
    } 

    public void calculate()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==j)
                    s1+=a[i][j];
                
                if(i+j==2)
                    s2+=a[i][j];
            }
        }
    }

    public void Display()
    {
        System.out.println("Left diagonal sum: "+ s1);
        System.out.println("Right diagonal sum: "+ s2);
    }

    public static void main(String[] args)
    {
        diagonalsum ds= new diagonalsum();
        ds.input();
        ds.calculate();
        ds.Display();
    }
}
