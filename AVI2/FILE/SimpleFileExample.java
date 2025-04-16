import java.io.*;

public class SimpleFileExample {
    public static void main(String[] args) {
        String filename = "sample.txt";

        // Writing to the file
        try (FileWriter writer = new FileWriter(filename)) {
            writer.write("Hello Tohid!\nWelcome to File Handling in Java.");
            System.out.println("File written successfully.");
        } catch (IOException e) {
            System.out.println("Error writing file: " + e);
        }

        // Reading from the file
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            System.out.println("\nReading from file:");
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e);
        }
    }
}
