class Hawk extends Bird {
    @Override void Fly()
    {
        System.out.println("Hawk doesn't flies high.");
    }

    @Override void makeSound()
    {
        System.out.println("Hawk flies loud.");
    }

    public static void main(String[] args) 
    {
        Hawk h=new Hawk();
        h.Fly();
        h.makeSound();
    }
}