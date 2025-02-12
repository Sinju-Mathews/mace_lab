import java.util.Scanner;

interface Comparable {
    public double volume();

    public int compareByVolume(Comparable other);
}

class Cuboid implements Comparable {
    double length, width, height;

    public Cuboid(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    public double volume() {
        return length * width * height;
    }

    public int compareByVolume(Comparable other) {
        if (volume() < other.volume())
            return -1;
        else if (volume() > other.volume())
            return 1;
        else
            return 0;
    }

    @Override
    public String toString() {
        return "volume of Cuboid :" + volume();
    }

}

class Cylinder implements Comparable {
    double radius, height;

    public Cylinder(double r, double h) {
        radius = r;
        height = h;
    }

    public double volume() {
        return Math.PI * radius * radius * height;
    }

    public int compareByVolume(Comparable other) {
        if (volume() < other.volume()) {
            return -1;
        } else if (volume() > other.volume()) {
            return 1;
        } else
            return 0;
    }

    @Override
    public String toString() {
        return "volume of Cylinder :" + volume();
    }

}

class Shape3D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("CUBOID: ");
        System.out.println("enter the length of cuboid");
        double l = sc.nextDouble();
        System.out.println("enter the width of cuboid");
        double w = sc.nextDouble();
        System.out.println("enter the height of cuboid");
        double h = sc.nextDouble();
        Comparable c1 = new Cuboid(l, w, h);
        System.out.println(c1);

        System.out.println("CYLINDER: ");
        System.out.println("enter the radius of cylinder");
        double r = sc.nextDouble();
        System.out.println("enter the height of cylinder");
        double h1 = sc.nextDouble();
        Comparable c2 = new Cylinder(r, h1);
        System.out.println(c2);

        int res = c1.compareByVolume(c2);
        if (res < 0)
            System.out.println("volume of cuboid is less than volume of cylinder");
        else if (res > 0)
            System.out.println("volume of cuboid is greater than volume of cylinder");
        else
            System.out.println("volume of cuboid is equal to volume of cylinder");

        sc.close();
    }

}