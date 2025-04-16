class MyThread extends Thread {
    private int threadPriority;

    // Constructor to set the priority of the thread
    public MyThread(int priority) {
        this.threadPriority = priority;
        setPriority(threadPriority);
    }

    @Override
    public void run() {
        // Print the thread's priority and name
        System.out.println(Thread.currentThread().getName() + " with priority " + getPriority() + " is running.");
    }
}

public class ThreadPriorityExample {
    public static void main(String[] args) {
        // Create threads with different priorities
        MyThread thread1 = new MyThread(Thread.MIN_PRIORITY);    // Thread with lowest priority (1)
        MyThread thread2 = new MyThread(Thread.NORM_PRIORITY);   // Thread with normal priority (5)
        MyThread thread3 = new MyThread(Thread.MAX_PRIORITY);    // Thread with highest priority (10)

        // Start the threads
        thread1.start();
        thread2.start();
        thread3.start();

        // Main thread also prints its own message
        System.out.println(Thread.currentThread().getName() + " with priority " + Thread.currentThread().getPriority() + " is running.");
    }
}
