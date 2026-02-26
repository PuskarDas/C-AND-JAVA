class Eagle extends Bird{
    @Override void Fly()
    {
        System.out.println("Eagle flies high.");
    }

    @Override void makeSound()
    {
        System.out.println("Eagle flies silent.");
    }

    public static void main(String[] args) 
    {
        Eagle e=new Eagle();
        e.Fly();
        e.makeSound();
    }
}
