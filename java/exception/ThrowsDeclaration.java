public class ThrowsDeclaration {
    public static char getCharFromStdin() throws java.io.IOException {
        System.out.print("Please enter a char: ");
        return (char) System.in.read();
    }

    public static void main(String[] args) {
        try {
            ThrowsDeclaration.getCharFromStdin();
        }
        catch(Throwable e){
            System.out.println("Exception occurred.");
        }
    }
}
