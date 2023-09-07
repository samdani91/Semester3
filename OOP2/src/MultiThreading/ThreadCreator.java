package MultiThreading;

public class ThreadCreator {
    public static void main(String[] args) {

        System.out.println("Creating Threads");

        Thread thread1 = new Thread(new PrintTask("Task 1"));

        Thread thread2 = new Thread(new PrintTask("Task 2"));

        Thread thread3 = new Thread(new PrintTask("Task 3"));

        System.out.println("Threads created!");

        thread1.start();

        thread2.start();

        thread3.start();

        System.out.println("Task started!");

    }
}
