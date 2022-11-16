public class ComplexNumberClass {
    public static void main(String[] args) {
        ComplexNumber a = new ComplexNumber();
        ComplexNumber b = new ComplexNumber();
        a.input();
        b.input();
        (a.Add(b)).display();
        (a.Subtract(b)).display();
        (a.Multiply(b)).display();

    }
}
