class OuterClass {

    public int x = 0;

    class InnerClass {

        public int x = 1;

        void methodOfInnerClass(int x) {
            System.out.println("x = " + x);
            System.out.println("this.x = " + this.x);
            System.out.println("OuterClass.this.x = " + OuterClass.this.x);
        }
    }
}

public class TestShadowing {
    public static void main(String... args) {
        OuterClass st = new OuterClass();
        OuterClass.InnerClass fl = st.new InnerClass();
        fl.methodOfInnerClass(23);
    }
}
