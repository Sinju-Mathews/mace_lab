import java.util.Scanner;

interface Printable{
    public void display();
    public void show();
}
interface Computable{
    public double area();
    public double perimeter();
    public double volume();
}

interface Drawable{
    public void draw();
    }

class Rectangle implements Printable, Computable, Drawable{
    private double length,width;
    public Rectangle(double l, double w) {
        length = l;
        width = w;
    }
        
    @Override
    public void display() {
        System.out.println("Length: "+length+" Width: "+width);
    }
    public void show() {}
    public double area() {
        return length*width;
    }
    public double perimeter() {
        return 2*(length+width);
        }
    public double volume() {
        return -1;
    }
    public void draw() {
        System.out.println("Drawing rectangle....");
        }
    }

    class Sphere implements Printable, Computable, Drawable{
    private double radius;
    public Sphere(double r) {
        radius = r;
    }
        
    @Override
    public void display() {
        System.out.println("Radius: "+radius);
    }
    public void show() {}
    public double area() {
        return 4.0*Math.PI*radius*radius;
    }
    public double perimeter() {
        return 2*Math.PI*radius;
        }
    public double volume() {
        return (4.0/3.0)*Math.PI*radius*radius*radius;
    }
    public void draw() {
        System.out.println("Drawing Sphere....");
        }
    }

    class ShapeDemo{
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the length of rectangle");
            double length = sc.nextDouble();
            System.out.println("Enter the width of rectangle");
            double width = sc.nextDouble();
            Rectangle r = new Rectangle(length,width);
            r.display();
            r.show();
            System.out.println("Area of rectangle: "+r.area());
            System.out.println("Perimeter of rectangle :"+r.perimeter());
            System.out.println("Volume of rectangle: "+r.volume());

            System.out.println("Enter the radius of the Sphere");
            double radius = sc.nextDouble();
            Sphere s = new Sphere(radius);
            s.display();
            s.show();
            System.out.println("Area of Sphere: "+s.area());
            System.out.println("Perimeter of Sphere: "+s.perimeter());
            System.out.println("Volume of Sphere: "+s.volume());
            sc.close();
            }
        }
    