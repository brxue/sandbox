class ArrayAsMethodParameter {
    public static void main(String[] args) {
        int [] array = {0, 1, 4, 8, 16};

        ArrayAsMethodParameter.DoubleArrayElement(array);
        for(int element:array) 
            System.out.print(element + " ");
        System.out.println();
    }

    static void DoubleArrayElement(int[] a)
    {
        for (int i=0; i<5; i++) {
            a[i] = 2 * a[i];
        }
    }
}
