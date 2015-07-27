package shapes;

public class Rectangle implements Shape {
    public void area() {
        System.out.println("Rectangle area.");
    }

    public static void main(String[] args) {
        Shape s = new Rectangle();
        s.area();
    }
}
