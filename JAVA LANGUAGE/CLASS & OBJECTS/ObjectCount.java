class Count 
{
    static int objectCount = 0; 

    Count() 
    {
        objectCount++; 
    }
}

public class ObjectCount 
{
    public static void main(String args[]) {
        Count obj1 = new Count();
        Count obj2 = new Count();
        Count obj3 = new Count();
        
        //Count obj4 = new Count();
        System.out.println("The number of objects created is : " + Count.objectCount);
    }
}
