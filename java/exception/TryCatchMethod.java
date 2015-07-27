class ExceptionInMethod {
    public static void triggerException() {
        int[] a = {0, 1, 4, 9};
        System.out.println("a[7] = " + a[7]);
    }
}

public class TryCatchMethod {
    public static void main(String[] args) {
        try {
            ExceptionInMethod.triggerException();
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Exception occurred, array access out of bound.");
        }
    }
}
