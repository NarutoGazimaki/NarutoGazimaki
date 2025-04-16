public class FactorialFibonacciPalindrome {

    // Method to calculate Factorial
    public static long factorial(int n) {
        long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    // Method to generate Fibonacci series up to n terms
    public static void fibonacci(int n) {
        int a = 0, b = 1;
        System.out.print("Fibonacci Series: ");
        for (int i = 1; i <= n; i++) {
            System.out.print(a + " ");
            int next = a + b;
            a = b;
            b = next;
        }
        System.out.println();
    }

    // Method to check if a number is Palindrome
    public static boolean isPalindrome(int num) {
        int original = num;
        int reversed = 0;
        while (num != 0) {
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        return original == reversed;
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide a number as a command-line argument.");
            return;
        }

        int choice = Integer.parseInt(args[0]);
        int number = 0;
        
        if (args.length > 1) {
            number = Integer.parseInt(args[1]);
        }

        switch (choice) {
            case 1: // Factorial
                System.out.println("Factorial of " + number + " is " + factorial(number));
                break;

            case 2: // Fibonacci
                fibonacci(number);
                break;

            case 3: // Palindrome
                if (isPalindrome(number)) {
                    System.out.println(number + " is a Palindrome.");
                } else {
                    System.out.println(number + " is not a Palindrome.");
                }
                break;

            default:
                System.out.println("Invalid choice.");
        }
    }
}
