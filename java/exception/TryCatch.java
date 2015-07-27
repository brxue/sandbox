class TryCatch {
    public static void main(String[] args) {
        int[] a = {0, 1, 4, 9};

        try {
            System.out.println("a[7] = " + a[7]);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Exception occurred, array access out of bound.");
        }
    }
}
