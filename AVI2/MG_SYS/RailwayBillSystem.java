import java.util.*;

public class RailwayBillSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String, Double> fareChart = new HashMap<>();
        Map<String, String> destinations = new HashMap<>();
        Map<String, Double> payments = new HashMap<>();
        List<String> passengers = new ArrayList<>();

        // Sample fare data (destination => fare)
        fareChart.put("Delhi", 500.0);
        fareChart.put("Mumbai", 800.0);
        fareChart.put("Chennai", 1000.0);
        fareChart.put("Kolkata", 600.0);

        int choice;
        do {
            System.out.println("\n--- RAILWAY BILL PAYMENT SYSTEM ---");
            System.out.println("1. Add Passenger & Book Ticket");
            System.out.println("2. View All Passengers");
            System.out.println("3. View All Bills Paid");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter Passenger Name: ");
                    String name = sc.nextLine();
                    if (passengers.contains(name)) {
                        System.out.println("Passenger already booked.");
                        break;
                    }
                    System.out.println("Available Destinations: " + fareChart.keySet());
                    System.out.print("Enter Destination: ");
                    String dest = sc.nextLine();

                    if (!fareChart.containsKey(dest)) {
                        System.out.println("Invalid destination.");
                        break;
                    }

                    double fare = fareChart.get(dest);
                    passengers.add(name);
                    destinations.put(name, dest);
                    payments.put(name, fare);
                    System.out.println("Ticket booked! Fare: ₹" + fare);
                    break;

                case 2:
                    System.out.println("\n--- Passenger List ---");
                    if (passengers.isEmpty()) {
                        System.out.println("No passengers found.");
                    } else {
                        for (String p : passengers) {
                            System.out.println(p + " -> " + destinations.get(p));
                        }
                    }
                    break;

                case 3:
                    System.out.println("\n--- Bill Payments ---");
                    if (payments.isEmpty()) {
                        System.out.println("No bills paid.");
                    } else {
                        for (Map.Entry<String, Double> entry : payments.entrySet()) {
                            System.out.println(entry.getKey() + " paid ₹" + entry.getValue());
                        }
                    }
                    break;

                case 4:
                    System.out.println("Exiting Railway System.");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 4);
    }
}
