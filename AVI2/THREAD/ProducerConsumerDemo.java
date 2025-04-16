class Buffer {
    int item;
    boolean available = false;

    // Producer adds item
    synchronized void produce(int value) {
        while (available) {
            try { wait(); } catch (Exception e) {}
        }
        item = value;
        available = true;
        System.out.println("Produced: " + item);
        notify();
    }

    // Consumer consumes item
    synchronized void consume() {
        while (!available) {
            try { wait(); } catch (Exception e) {}
        }
        System.out.println("Consumed: " + item);
        available = false;
        notify();
    }
}

public class ProducerConsumerDemo {
    public static void main(String[] args) {
        Buffer buffer = new Buffer();

        // Producer thread
        Thread producer = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                buffer.produce(i);
                try { Thread.sleep(400); } catch (Exception e) {}
            }
        });

        // Consumer thread
        Thread consumer = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                buffer.consume();
                try { Thread.sleep(500); } catch (Exception e) {}
            }
        });

        producer.start();
        consumer.start();
    }
}
