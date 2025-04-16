import java.util.*;

public class FeesSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String, Double> feeRecords = new HashMap<>();
        List<String> studentList = new ArrayList<>();

        int choice;
        do {
            System.out.println("\n--- FEES MANAGEMENT SYSTEM ---");
            System.out.println("1. Add Student");
            System.out.println("2. Pay Fees");
            System.out.println("3. View All Students");
            System.out.println("4. View Fee Records");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // clear newline

            switch (choice) {
                case 1:
                    System.out.print("Enter Student Name: ");
                    String student = sc.nextLine();
                    if (!studentList.contains(student)) {
                        studentList.add(student);
                        System.out.println("Student added.");
                    } else {
                        System.out.println("Student already exists.");
                    }
                    break;

                case 2:
                    System.out.print("Enter Student Name: ");
                    String name = sc.nextLine();
                    if (studentList.contains(name)) {
                        System.out.print("Enter Fee Amount: ₹");
                        double amount = sc.nextDouble();
                        sc.nextLine();
                        feeRecords.put(name, feeRecords.getOrDefault(name, 0.0) + amount);
                        System.out.println("Fee updated.");
                    } else {
                        System.out.println("Student not found. Please add student first.");
                    }
                    break;

                case 3:
                    System.out.println("\n--- Student List ---");
                    if (studentList.isEmpty()) {
                        System.out.println("No students found.");
                    } else {
                        for (String s : studentList) {
                            System.out.println("- " + s);
                        }
                    }
                    break;

                case 4:
                    System.out.println("\n--- Fee Records ---");
                    if (feeRecords.isEmpty()) {
                        System.out.println("No fees recorded.");
                    } else {
                        for (Map.Entry<String, Double> entry : feeRecords.entrySet()) {
                            System.out.println(entry.getKey() + " paid ₹" + entry.getValue());
                        }
                    }
                    break;

                case 5:
                    System.out.println("Exiting Fees System.");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 5);
    }
}
