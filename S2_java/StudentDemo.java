import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public class StudentDemo{
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    HashMap <Integer ,String > student = new HashMap<>();
    System.out.print("enter the number of students: ");
    int n=sc.nextInt();
    for(int i=1;i<=n;i++){
        System.out.print("enter the roll number of student "+i+" :");
        int roll=sc.nextInt();
        sc.nextLine();
        System.out.print("enter the name of student "+i+" :");
        String name=sc.nextLine();
        student.put(roll,name);
    }
    int ch;
    do{
        System.out.println("enter the rollno. to find student");
        int rollno=sc.nextInt();
        System.out.println("student name is "+student.get(rollno));
        System.out.println("do you want to search another student?");
        System.out.println("1. yes\n2. No");
        ch=sc.nextInt();
        }while(ch==1);
        sc.close();
    }
    }
 