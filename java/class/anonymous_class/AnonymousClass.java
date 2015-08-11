class HelloWorld {
    public void hello() {
        System.out.println("Hello World!");
    }
}

public class AnonymousClass {
    public static void main(String []args) {
        HelloWorld chineseHello = new HelloWorld() {
            public void hello() {
                System.out.println("Nihao World!");
            }
        };

        HelloWorld spanishHello = new HelloWorld() {
            public void hello() {
                System.out.println("Halo World!");
            }
        };

        chineseHello.hello();
        spanishHello.hello();
    }
}
