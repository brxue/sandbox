class OuterClass {

    String scope1 = "[OuterClass]";

    public void goodbye() {
        final String scope2 = "[goodbye]: ";

        class LocalClass1 {
            void englishGoodbye() {
                System.out.println(scope1 + scope2 + "Bye Bye!");
            }
        }

        class LocalClass2 {
            void chineseGoodbye() {
                System.out.println(scope1 + scope2 + "Zai Jian!");
            }
        }
        
        LocalClass1 objLocal1 = new LocalClass1();
        objLocal1.englishGoodbye();

        LocalClass2 objLocal2 = new LocalClass2();
        objLocal2.chineseGoodbye();
    }
}

public class TestLocalClass {
    public static void main(String [] args) {
        OuterClass obj = new OuterClass();
        obj.goodbye();
    }
}
