class NestedTry {
    public static void main(String[] args) {
        int[] a = {2, 4, 8, 16, 32};
        int[] b = {1, 2, 0, 4};

        try {
            for (int i=0; i<a.length; i++) {
                try {
                        System.out.printf("%d/%d = %d\n", a[i], b[i], a[i]/b[i]);
                }
                catch (ArrayIndexOutOfBoundsException e1) {
                    System.out.println("Out of array bounds, this line will never happen in this example.");
                }
            }
        }
        catch (ArithmeticException e2) {
            System.out.println("Can't divide by zero, this will terminate the for loop.");
        }

        System.out.println("Program End.");
    }
}

