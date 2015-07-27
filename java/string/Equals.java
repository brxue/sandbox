class Equals {
    public static void main(String[] args) {
        String s1 = new String("Hello World!");
        String s2 = new String("Hello World!");

        assert s1.equals(s2);
        assert s1 != s2;

        String s3 = s1;
        assert s3 == s1;
    }
}
