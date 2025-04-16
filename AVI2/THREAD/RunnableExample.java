class MyRunnable implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(500);
                System.out.println(Thread.currentThread().getName() + " - " + i);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class RunnableExample {
    public static void main(String[] args) {
        Thread thread1 = new Thread(new MyRunnable());
        Thread thread2 = new Thread(new MyRunnable());

        thread1.start();
        thread2.start();

        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(500);
                System.out.println(Thread.currentThread().getName() + " (Main) - " + i);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
