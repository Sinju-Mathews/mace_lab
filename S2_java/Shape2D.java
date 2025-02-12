import java.util.Scanner;
interface Computable{
    public double perimeter();
    public double area();
}

class Rectangle implements Computable{
    private double length;
    private double width;
    public Rectangle(double l, double w) {
        this.length=l;
        this.width=w;
    }
    public double perimeter(){return 2*(length + width);}
    public double area(){return length * width;}

    @Override
    public String toString(){
        return "Rectangle: \n Area:" +area()+"\n Perimeter :"+perimeter();
    }
}

class Circle implements Computable{
    private double radius;
    public Circle(double r) {
        this.radius=r;
    }
    public double perimeter(){return 2*Math.PI*radius;}
    public double area(){return Math.PI*radius*radius;}

    @Override
    public String toString(){
        return "Circle: \n Area:" +area()+"\n Perimeter :"+perimeter();
    }
}
class Shape2D{
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println("1. Rectangle \n2.Circle \n3.Exit");

int ch;
do{
    System.out.println("Enter your choice");
    ch = sc.nextInt();
    switch(ch){
        case 1: {
            System.out.println("RECTANGLE");
            System.out.println("Enter length and width");
            double l = sc.nextDouble();
            double w = sc.nextDouble();
            Computable r = new Rectangle(l, w);
            System.out.println(r);
            break;
            }
        case 2:{
            System.out.println("CIRCLE");
            System.out.println("Enter radius");
            double r=sc.nextDouble();
            Computable c = new Circle(r);
            System.out.println(c);
            break;
        }
        case 3:{
            System.out.println("Exiting...");
            break;
        }
}
}while(ch!=3);
sc.close();
}

}
