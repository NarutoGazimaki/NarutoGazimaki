import java.util.*;

public class VotingSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String, Boolean> voterList = new HashMap<>();
        Map<String, Integer> votes = new HashMap<>();

        int choice;
        do {
            System.out.println("\n--- VOTING SYSTEM ---");
            System.out.println("1. Register Voter");
            System.out.println("2. Cast Vote");
            System.out.println("3. Show Results");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter Voter ID: ");
                    String id = sc.nextLine();
                    if (!voterList.containsKey(id)) {
                        voterList.put(id, false); // not voted yet
                        System.out.println("Voter registered.");
                    } else {
                        System.out.println("Voter already exists.");
                    }
                    break;

                case 2:
                    System.out.print("Enter Voter ID: ");
                    String voterId = sc.nextLine();
                    if (voterList.containsKey(voterId) && !voterList.get(voterId)) {
                        System.out.print("Enter Candidate Name: ");
                        String candidate = sc.nextLine();
                        votes.put(candidate, votes.getOrDefault(candidate, 0) + 1);
                        voterList.put(voterId, true); // mark as voted
                        System.out.println("Vote cast successfully.");
                    } else {
                        System.out.println("Invalid ID or already voted.");
                    }
                    break;

                case 3:
                    System.out.println("Vote Results:");
                    for (Map.Entry<String, Integer> entry : votes.entrySet()) {
                        System.out.println(entry.getKey() + " - " + entry.getValue() + " votes");
                    }
                    break;

                case 4:
                    System.out.println("Exiting Voting System.");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }
        } while (choice != 4);
    }
}
