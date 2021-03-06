class CatchWithSuperClass {
    public static void main(String[] args) {
        int[] a = {2, 4, 8, 16, 32};
        int[] b = {1, 2, 0, 4};

        for (int i=0; i<a.length; i++) {
            try {
                    System.out.printf("%d/%d = %d\n", a[i], b[i], a[i]/b[i]);
            }
            catch (ArithmeticException e1) {
                System.out.println("Can't divide by zero.");
            }
            catch (Exception e2) {
                System.out.println("Catch ArrayIndexOutOfBoundsException with Exception class.");
            }
        }

        System.out.println("Program End.");
    }
}

