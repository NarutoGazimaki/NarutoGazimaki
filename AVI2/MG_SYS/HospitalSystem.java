import java.util.*;

public class HospitalSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<String> patients = new ArrayList<>();
        List<String> doctors = new ArrayList<>();

        int choice;
        do {
            System.out.println("\n--- HOSPITAL MANAGEMENT SYSTEM ---");
            System.out.println("1. Add Patient");
            System.out.println("2. Add Doctor");
            System.out.println("3. View Patients");
            System.out.println("4. View Doctors");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter Patient Name: ");
                    String patientName = sc.nextLine();
                    patients.add(patientName);
                    System.out.println("Patient added.");
                    break;

                case 2:
                    System.out.print("Enter Doctor Name: ");
                    String doctorName = sc.nextLine();
                    doctors.add(doctorName);
                    System.out.println("Doctor added.");
                    break;

                case 3:
                    System.out.println("\n--- Patient List ---");
                    if (patients.isEmpty()) {
                        System.out.println("No patients found.");
                    } else {
                        for (String p : patients) {
                            System.out.println("- " + p);
                        }
                    }
                    break;

                case 4:
                    System.out.println("\n--- Doctor List ---");
                    if (doctors.isEmpty()) {
                        System.out.println("No doctors found.");
                    } else {
                        for (String d : doctors) {
                            System.out.println("- Dr. " + d);
                        }
                    }
                    break;

                case 5:
                    System.out.println("Exiting Hospital System.");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }
        } while (choice != 5);
    }
}
