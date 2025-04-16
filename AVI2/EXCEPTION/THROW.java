import java.util.Scanner;

public class THROW {

    // Method that throws an exception if number is negative
    static void checkNumber(int num) throws ArithmeticException {
        if (num < 0) {
            throw new ArithmeticException("Negative number not allowed.");
        } else {
            System.out.println("Valid number: " + num);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        try {
            System.out.print("Enter a number: ");
            int number = sc.nextInt();

            // Call the method that may throw an exception
            checkNumber(number);
        } catch (ArithmeticException e) {
            System.out.println("Caught Exception: " + e.getMessage());
        }

        System.out.println("Program continues after try-catch...");
    }
}
