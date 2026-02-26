public class BirdMain {
    public static void main(String []args) {
        Bird bird1; // Reference of Parent Class
        
        bird1=new Eagle();
        bird1.Fly(); 
        bird1.makeSound(); 
        
        bird1=new Hawk(); 
        bird1.Fly();
        bird1.makeSound(); 
        System.out.println();
        
        Bird[] bird2={new Eagle(), new Hawk()}; //loop over an array

        for(Bird b : bird2)
        {
            b.Fly();
            b.makeSound();
        }
    }
}
