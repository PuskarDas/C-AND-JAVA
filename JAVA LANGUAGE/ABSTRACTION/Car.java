class Car extends Vehicle
{
    @Override void startEngine()
    {
        System.out.println("Engine started first.");
    }

    @Override void stopEngine()
    {
        System.out.println("Engine stopped first.");
    }

    public static void main(String[] args) 
    {
        ob=new Car();
        ob.startEngine();
        ob.stopEngine();
    }
}