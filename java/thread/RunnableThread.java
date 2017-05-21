class MyRunnable implements Runnable {
    String name;

    MyRunnable(String name) {
        this.name = name;
    }

    public void run() {
        System.out.println(this.name + " starting...");
        
        try {
            for (int i=0; i<5; i++) {
                Thread.sleep(1+ (int)(Math.random()*100));
                System.out.println("In " + this.name + ": i=" + i);
            }
        }
        catch (InterruptedException e) {
            System.out.println(this.name + " interrupted.");
        }

        System.out.println(this.name + " ending...");
    }
}

public class RunnableThread {
    public static void main(String args[]) {
        System.out.println("Mainthread starting...");

        Thread th1 = new Thread(new MyRunnable("thread1"), "thread1");
        Thread th2 = new Thread(new MyRunnable("thread2"), "thread2");

        System.out.println("Thread1 name = " + th1.getName());
        System.out.println("Thread2 name = " + th2.getName());

        th1.start();
        th2.start();

        try {
            th1.join();
        }
        catch (InterruptedException e) {
            System.out.println(th1.getName() + " interrupted when join.");
        }

        try {
            th2.join();
        }
        catch (InterruptedException e) {
            System.out.println(th2.getName() + " interrupted when join.");
        }

        System.out.println("Mainthread ending...");
    }
}
