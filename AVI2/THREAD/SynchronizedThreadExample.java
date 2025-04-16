package THREAD;
class Bank {
    int balance = 1000;

    // synchronized method to withdraw money
    synchronized void withdraw(int amount) {
        System.out.println(Thread.currentThread().getName() + " is trying to withdraw ₹" + amount);

        if (balance >= amount) {
            System.out.println("Processing withdrawal...");
            try {
                Thread.sleep(1000); // simulate delay
            } catch (InterruptedException e) {
                System.out.println(e);
            }
            balance -= amount;
            System.out.println(Thread.currentThread().getName() + " completed withdrawal. Remaining balance: ₹" + balance);
        } else {
            System.out.println("Insufficient balance for " + Thread.currentThread().getName());
        }
    }
}

class CustomerThread extends Thread {
    Bank bank;
    int amount;

    CustomerThread(Bank bank, int amount, String name) {
        super(name);
        this.bank = bank;
        this.amount = amount;
    }

    @Override
    public void run() {
        bank.withdraw(amount);
    }
}

public class SynchronizedThreadExample {
    public static void main(String[] args) {
        Bank bank = new Bank();

        CustomerThread c1 = new CustomerThread(bank, 700, "Customer-1");
        CustomerThread c2 = new CustomerThread(bank, 500, "Customer-2");

        c1.start();
        c2.start();
    }
}
