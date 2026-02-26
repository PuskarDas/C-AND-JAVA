class Cube extends Shape3D {
    double side;

    @Override double volume()
    {
        return Math.pow(side,3);
    }
    @Override double surfaceArea()
    {
        return 6.0*Math.pow(side,2);
    }

    public static void main(String[] args) {
        Cube c=new Cube();
        c.side=5.0;
        double v=c.volume();
        double a=c.surfaceArea();

        System.out.println("Volume: "+ v);
        System.out.println("Surface Area: "+ a);
    }
}