class OuterClass {
    static class StaticNestedClass {
        static void hello() {
            System.out.println("Hello World!");
        }
    }
}

public class TestStaticNestedClass {
    public static void main(String [] args) {
        OuterClass.StaticNestedClass nestedObject = new OuterClass.StaticNestedClass();
        nestedObject.hello();
    }
}


