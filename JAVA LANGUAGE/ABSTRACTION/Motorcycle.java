class Motorcycle extends Vehicle
{
    @Override void startEngine()
    {
        System.out.println("Engine started next.");
    }

    @Override void stopEngine()
    {
        System.out.println("Engine stopped next.");
    }

    public static void main(String[] args) 
    {
        ob=new Motorcycle();
        ob.startEngine();
        ob.stopEngine();
    }

}
