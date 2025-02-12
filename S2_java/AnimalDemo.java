import java.util.Scanner;

class Animal {
    private String species;
    int age;
    double weight;
    protected String color;

    public Animal(String s, int a, double w, String c) {
        species = s;
        age = a;
        weight = w;
        color = c;
    }

    public void display() {
        System.out.println("Species:" + species + "\nage: " + age + "\nweight: " + weight + "kg \ncolor: " + color);
    }
}

class Dog extends Animal {
    private String name;
    private String owner;

    public Dog(String s, int a, double w, String c, String n, String o) {
        super(s, a, w, c);
        name = n;
        owner = o;
    }

    public void display() {
        super.display();
        System.out.println("name:" + name + "\nowner: " + owner);
    }
}

class Cat extends Animal {
    private String name;
    private String eyecolor;
    int taillength;

    public Cat(String s, int a, double w, String c, String n, String eye, int tail) {
        super(s, a, w, c);
        name = n;
        eyecolor = eye;
        taillength = tail;
    }

    public void display() {
        super.display();
        System.out.println("name:" + name + "\neyecolor: " + eyecolor + "\nTail Length: " + taillength + "cm");
    }
}

class AnimalDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Details of the DOG: ");
        System.out.print("Enter the Species: ");
        String s = sc.next();
        System.out.print("Enter the Age: ");
        int age = sc.nextInt();
        System.out.print("Enter the Weight(in kg): ");
        double we = sc.nextDouble();
        System.out.print("Enter the Color: ");
        String color = sc.next();
        System.out.print("Enter the Name: ");
        String name = sc.next();
        System.out.print("Name of the owner: ");
        String owner = sc.next();

        Dog d = new Dog(s, age, we, color, name, owner);

        System.out.println("Enter the Details of the CAT: ");
        System.out.print("Enter the Species: ");
        s = sc.next();
        System.out.print("Enter the Age: ");
        age = sc.nextInt();
        System.out.print("Enter the Weight(in kg): ");
        we = sc.nextDouble();
        System.out.print("Enter the Color: ");
        color = sc.next();
        System.out.print("Enter the Name: ");
        name = sc.next();
        System.out.print("Color of the eye: ");
        String eye = sc.next();
        System.out.print("Length of the tail: ");
        int tail = sc.nextInt();

        Cat c = new Cat(s, age, we, color, name, eye, tail);
        d.display();
        c.display();
        sc.close();
    }
}