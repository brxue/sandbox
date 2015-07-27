public class Constructor {
    public static void main(String[] args) {
        String s1 = new String("Hello World!");
        assert s1.equals("Hello World!");

        char [] helloArray = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
        String s2 = new String(helloArray);
        assert s2.equals("Hello World!");

        String s3 = new String(helloArray, 2, 3);
        assert s3.equals("llo");

        String s4 = new String(s3);
        assert s4.equals(s3);
    }
}
