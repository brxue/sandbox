class MultiCatchOr {
    public static void main(String[] args) {
        int[] a = {2, 4, 8, 16, 32};
        int[] b = {1, 2, 0, 4};

        for (int i=0; i<a.length; i++) {
            try {
                    System.out.printf("%d/%d = %d\n", a[i], b[i], a[i]/b[i]);
            }
            catch (ArithmeticException | ArrayIndexOutOfBoundsException  e) {
                System.out.println("Exception occurred: " + e);
            }
        }

        System.out.println("Program End.");
    }
}

