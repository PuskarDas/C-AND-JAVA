public class Sphere extends Shape3D {
    double radius;

    @Override double volume()
    {
        return 4.0/3*Math.PI*Math.pow(radius,3);
    }
    @Override double surfaceArea()
    {
        return 4.0*Math.PI*Math.pow(radius,2);
    }

    public static void main(String[] args) {
        Sphere s=new Sphere();
        s.radius=5.0;
        double v=s.volume();
        double a=s.surfaceArea();

        System.out.println("Volume: "+ v);
        System.out.println("Surface Area: "+ a);
    }
}