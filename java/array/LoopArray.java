class LoopArray {
    public static void main(String[] args) {
        int [] a = new int[5];

        for (int i=0; i<5; i++) {
            a[i] = i*i;
        }

        int j = 0;
        while (j < 5) {
            System.out.print(a[j] + " ");
            j++;
        }
        System.out.println();
    }
}
