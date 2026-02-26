abstract class Manager implements Staff
{
    public double earnings(double basic){
        return basic+0.8*basic+0.15*basic;
    }
    public double deductions(double basic){
        return 0.12*basic;
    } 
    public abstract double bonus(double basic);
}

