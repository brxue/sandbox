class MyRunnable implements Runnable {
    String name;
    Thread thread;

    MyRunnable(String name) {
        this.name = name;
        this.thread = new Thread(this, name);
        this.thread.start();
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

public class RunnableThread2 {
    public static void main(String args[]) {
        System.out.println("Mainthread starting...");

        MyRunnable run1 = new MyRunnable("thread1");
        MyRunnable run2 = new MyRunnable("thread2");

        try {
            run1.thread.join();
        }
        catch (InterruptedException e) {
            System.out.println(run1.thread.getName() + " interrupted when join.");
        }

        try {
            run2.thread.join();
        }
        catch (InterruptedException e) {
            System.out.println(run2.thread.getName() + " interrupted when join.");
        }

        System.out.println("Mainthread ending...");
    }
}
