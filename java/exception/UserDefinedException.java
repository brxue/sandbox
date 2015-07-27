class MyExceptionType extends Exception {
    int a;

    MyExceptionType(int a) {
        this.a = a;
    }

    public String toString() {
        return "The number is " + a;
    }
}

class UserDefinedException {
    public static void main(String[] args) {
        int[] a = {0, 0, 4, 0};

        try {
            for (int i=0; i<4; i++) {
                if (a[i] != 0) 
                    throw(new MyExceptionType(a[i]));
                else 
                    System.out.printf("a[%d] == 0.\n", i);
            }
        }
        catch(MyExceptionType e){
            System.out.println("Exception occurred: " + e);
        }
    }
}
