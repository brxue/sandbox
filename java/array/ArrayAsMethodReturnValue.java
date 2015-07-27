class ArrayAsMethodReturnValue {
    public static void main(String[] args) {

        int [] array = ArrayAsMethodReturnValue.getArray();
        for(int element:array) 
            System.out.print(element + " ");
        System.out.println();
    }

    static int[] getArray()
    {
        int [] a = {0, 1, 4, 8, 16};

        for (int i=0; i<5; i++) {
            a[i] = 2 * a[i];
        }

        return a;
    }
}
