public class MyFirstClass {
    public static void main(String[] args) {
        // Rectangle X //will not work because X needs the memory and new Rectangle() is
        // assigning here the memory
        Rectangle X = new Rectangle();
        X.input();
        X.calculate();
        X.display();
        Rectangle Y = new Rectangle();
        Y.input();
        Y.calculate();
        Y.display();
    }
}
