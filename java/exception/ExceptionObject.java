class ExceptionInMethod {
    public static void triggerException() {
        int[] a = {0, 1, 4, 9};
        System.out.println("a[7] = " + a[7]);
    }
}

public class ExceptionObject {
    public static void main(String[] args) {
        try {
            ExceptionInMethod.triggerException();
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Exception occurred, array access out of bound.");

            System.out.println("\ngetMessage():");
            System.out.println(e.getMessage());

            System.out.println("\ntoString():");
            System.out.println(e);

            System.out.println("\nprintStackTrace():");
            e.printStackTrace();
        }
    }
}
