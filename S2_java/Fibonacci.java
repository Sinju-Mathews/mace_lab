import java.util.Scanner;
public class Fibonacci {
    public static void fibonacci(int n) {
        int a = 0;
        int b = 1;
        System.out.print(a + " " + b);
        for (int i = 2; i < n; i++) {
            int c = a + b;
            a = b;
            b=c;
            System.out.print(" " + c);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter n: ");
        int n = sc.nextInt();
        fibonacci(n);
        sc.close();
    }
}
