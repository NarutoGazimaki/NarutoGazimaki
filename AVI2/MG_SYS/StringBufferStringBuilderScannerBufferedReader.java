import java.io.*;
import java.util.*;

public class StringBufferStringBuilderScannerBufferedReader {

    public static void main(String[] args) throws IOException {
        // Demonstrating StringBuffer
        StringBuffer sb = new StringBuffer("Hello");
        sb.append(" World");
        System.out.println("StringBuffer Output: " + sb.toString());

        // Demonstrating StringBuilder
        StringBuilder builder = new StringBuilder("Hello");
        builder.append(" Java");
        System.out.println("StringBuilder Output: " + builder.toString());

        // Demonstrating Scanner (for reading a name)
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter your name (using Scanner): ");
        String nameScanner = scanner.nextLine();
        System.out.println("Hello, " + nameScanner + " (Scanner)");

        // Demonstrating BufferedReader (for reading a line)
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter a line of text (using BufferedReader): ");
        String lineReader = reader.readLine();
        System.out.println("You entered (BufferedReader): " + lineReader);
    }
}
