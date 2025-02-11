class AREA{
    public int area(int l, int b)
    {
        return l*b;
    }
    public double area(double l, double b)
    {
        return l*b;
    }
    public int area(int s)
    {
        return s*s;
    }
    public double area(double s)
    {
        return s*s;
    }
    public double area( double b, double h, String shape)
    {
      
        return 0.5*b*h;
        
    }
    public double area(double r, String shape)
    {
        
        return Math.PI*r*r;
    }

}
public class AreaOverload{
    public static void main(String [] args)
    {
        AREA a=new AREA();

        int rect1=a.area(5,6);
        System.out.println("Area of rectangle (int):" +rect1);

        double rect2=a.area(5.0,6.5);
        System.out.println("Area of rectangle (double):" +rect2);

        int sq1=a.area(5);
        System.out.println("Area of square(int) :" +sq1);

        double sq2=a.area(5.6);
        System.out.println("Area of square (double) :" +sq2);

        double cir=a.area(4.6,"circle");
        System.out.println("Area of circle :" +cir);
        
        double tri=a.area(5.4,2.3,"triangle");
        System.out.println("Area of triangle :" +tri);

    }
}