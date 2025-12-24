package class_activity5;

public class Bank implements Runnable {

    static int balance = 0;

    @Override
    public void run() {
        // Synchronized block ensures only one thread at a time
        synchronized (Bank.class) {
            deposit();
            System.out.println("[AFTER] After deposit " + Thread.currentThread().getName() + " Balance=" + getValue());
            withdraw();
            System.out.println("[AFTER] After withdraw " + Thread.currentThread().getName() + " Balance=" + getValue());
        }
    }

    public void deposit() {
        balance += 100;
    }

    public void withdraw() {
        balance -= 100;
    }

    public int getValue() {
        return balance;
    }
}
