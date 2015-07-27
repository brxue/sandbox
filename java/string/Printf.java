class Printf {
    public static void main(String[] args) {
        int intVar = 4;
        double doubleVar = 2.3;
        String stringVar = "Hello";

        System.out.printf("The value of the double variable is " +
                          "%f, while the value of the integer " +
                          "variable is %d, and the string " +
                          "is %s", doubleVar, intVar, stringVar);
        System.out.println();
    }
}
