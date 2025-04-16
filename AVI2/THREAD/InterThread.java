package THREAD;
class Shared {
    int data;
    boolean available = false;

    synchronized void produce(int value) {
        while (available) {
            try { wait(); } catch (Exception e) {}
        }
        data = value;
        System.out.println("Produced: " + data);
        available = true;
        notify();
    }

    synchronized void consume() {
        while (!available) {
            try { wait(); } catch (Exception e) {}
        }
        System.out.println("Consumed: " + data);
        available = false;
        notify();
    }
}

public class InterThread {
    public static void main(String[] args) {
        Shared s = new Shared();

        new Thread(() -> {
            for (int i = 1; i <= 5; i++) s.produce(i);
        }).start();

        new Thread(() -> {
            for (int i = 1; i <= 5; i++) s.consume();
        }).start();
    }
}
