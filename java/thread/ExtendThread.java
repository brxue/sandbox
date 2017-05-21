class MyThread extends Thread {
    MyThread(String name) {
        super(name);
    }

    public void run() {
        System.out.println(this.getName() + " starting...");
        
        try {
            for (int i=0; i<5; i++) {
                Thread.sleep(1+ (int)(Math.random()*100));
                System.out.println("In " + this.getName() + ": i=" + i);
            }
        }
        catch (InterruptedException e) {
            System.out.println(this.getName() + " interrupted.");
        }

        System.out.println(this.getName() + " ending...");
    }
}

public class ExtendThread {
    public static void main(String args[]) {
        System.out.println("Mainthread starting...");

        MyThread th1 = new MyThread("thread1");
        MyThread th2 = new MyThread("thread2");

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
