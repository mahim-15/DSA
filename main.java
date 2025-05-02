import java.util.Scanner;

class Sum {
   
    // Constructor for int
   void  printSum(int num1, int num2) {
       
        System.out.println("Sum = " + (num1 + num2));
    }

    // Constructor for long
    void printSum( long num1, long num2) {
        System.out.println("Sum2 = " + (num1 + num2));
    }
}

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two integers: or two long \n");
        Sum first = new Sum();
        first.printSum(10, 200);
        first.printSum(100000000L,593990L);
    }
}
