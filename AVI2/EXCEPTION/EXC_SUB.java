// Custom exception class
class AgeCheckException extends Exception {
    // Constructor
    public AgeCheckException(String message) {
        super(message); // Pass message to parent Exception class
    }
}

public class EXC_SUB {

    // Method to check age
    static void checkAge(int age) throws AgeCheckException {
        if (age < 18) {
            throw new AgeCheckException("You must be at least 18 years old.");
        } else {
            System.out.println("Access granted. Age: " + age);
        }
    }

    public static void main(String[] args) {
        try {
            int age = 15; // You can also take input from user
            checkAge(age);
        } catch (AgeCheckException e) {
            System.out.println("Custom Exception Caught: " + e.getMessage());
        }

        System.out.println("Program continues...");
    }
}
