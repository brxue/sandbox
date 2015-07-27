class TryCatchFinally {
    public static void main(String[] args) {
        int[] a = {0, 1, 4, 9};
        
        try {
            if (args[0].equals("trigger"))
                System.out.println("a[7] = " + a[7]);
            else
                System.out.println("a[3] = " + a[3]);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Exception occurred, array access out of bound.");
        }
        finally
        {
            System.out.println("This line will be printed whatever exception occur or not.");
        }

        System.out.println("Program End.");
    }
}
