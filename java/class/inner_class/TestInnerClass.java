class OuterClass {
    int x = 8;

    void printX() {
        System.out.println("x = " + x);
    }

    class InnerClass {
        void printMemberVariableOfOuterClass() {
            System.out.println("Print member variable x of OuterClass: " + x);
        }
        void callMemberFunctionOfOuterClass() {
            printX();
        }
    }
}

public class TestInnerClass {
    public static void main(String [] args) {
        OuterClass outerObject= new OuterClass();
        OuterClass.InnerClass innerObject = outerObject.new InnerClass();

        innerObject.printMemberVariableOfOuterClass();
        innerObject.callMemberFunctionOfOuterClass();
    }
}
