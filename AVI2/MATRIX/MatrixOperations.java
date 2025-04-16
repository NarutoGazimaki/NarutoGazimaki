import java.util.Scanner;

public class MatrixOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] A, B;
        int rows, cols;

        System.out.println("Enter number of rows: ");
        rows = sc.nextInt();
        System.out.println("Enter number of columns: ");
        cols = sc.nextInt();

        A = new int[rows][cols];
        B = new int[rows][cols];

        System.out.println("Enter elements of Matrix A:");
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                A[i][j] = sc.nextInt();

        System.out.println("Enter elements of Matrix B:");
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                B[i][j] = sc.nextInt();

        int choice;
        do {
            System.out.println("\n--- MATRIX OPERATIONS ---");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Transpose (Matrix A)");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("\nMatrix Addition:");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            System.out.print((A[i][j] + B[i][j]) + " ");
                        }
                        System.out.println();
                    }
                    break;

                case 2:
                    System.out.println("\nMatrix Subtraction:");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            System.out.print((A[i][j] - B[i][j]) + " ");
                        }
                        System.out.println();
                    }
                    break;

                case 3:
                    if (cols != rows) {
                        System.out.println("Matrix multiplication requires A.cols == B.rows");
                        break;
                    }
                    int[][] result = new int[rows][cols];
                    System.out.println("\nMatrix Multiplication:");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            result[i][j] = 0;
                            for (int k = 0; k < cols; k++) {
                                result[i][j] += A[i][k] * B[k][j];
                            }
                            System.out.print(result[i][j] + " ");
                        }
                        System.out.println();
                    }
                    break;

                case 4:
                    System.out.println("\nTranspose of Matrix A:");
                    for (int i = 0; i < cols; i++) {
                        for (int j = 0; j < rows; j++) {
                            System.out.print(A[j][i] + " ");
                        }
                        System.out.println();
                    }
                    break;

                case 5:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 5);
    }
}
