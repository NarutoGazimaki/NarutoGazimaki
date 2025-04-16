class Task1 extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(500);
                System.out.println(Thread.currentThread().getName() + " - Task1: " + i);
            } catch (InterruptedException e) {
                e.printStackTrace(); // Better error visibility
            }
        }
    }
}

class Task2 implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(500);
                System.out.println(Thread.currentThread().getName() + " - Task2: " + i);
            } catch (InterruptedException e) {
                e.printStackTrace(); // Better error visibility
            }
        }
    }
}

public class MultiThreadExample {
    public static void main(String[] args) {
        Task1 thread1 = new Task1(); // Extending Thread
        Thread thread2 = new Thread(new Task2()); // Using Runnable

        thread1.start();
        thread2.start();

        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(500);
                System.out.println(Thread.currentThread().getName() + " (Main) - " + i);
            } catch (InterruptedException e) {
                e.printStackTrace(); // Better error visibility
            }
        }
    }
}
