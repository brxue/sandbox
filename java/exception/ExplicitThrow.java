class ExplicitThrow {
    public static void main(String[] args) {
        System.out.println("This code will trigger exception intentionally.");
        throw (new ArrayIndexOutOfBoundsException());
    }
}
