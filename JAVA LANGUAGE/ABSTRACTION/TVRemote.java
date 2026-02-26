class TVRemote extends TV
{
    @Override void turnOn()
    {
        System.out.println("TV is turned ON.");
    }

    @Override void turnOff()
    {
        System.out.println("TV is turned OFF.");
    }
    public static void main(String[] args)    // Main class to demonstrate abstraction
    {    
        TVRemote remote = new TVRemote();
        remote.turnOn();   
        remote.turnOff();  
    }
}