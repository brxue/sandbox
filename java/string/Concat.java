class Concat {
    public static void main(String[] args) {
        String s1 = "Hello";
        String s2 = " World!";
        assert s1.concat(s2).equals("Hello World!");
        assert (s1 + s2).equals("Hello World!");
    }
}
