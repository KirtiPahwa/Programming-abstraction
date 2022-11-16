import java.util.Scanner;

class Rectangle {
    private float l;
    private float b;
    private float area;
    private float perimeter;

    public void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the Rectangle");
        l = sc.nextFloat();

        System.out.println("Enter the width of the Rectangle");
        b = sc.nextFloat();
        sc.close();
    }

    public void calculate() {
        area = l * b;
        perimeter = 2 * (l + b);
    }

    public void display() {
        System.out.println("Length=" + l);
        System.out.println("Width=" + b);
        System.out.println("Area=" + area);
        System.out.println("Perimeter=" + perimeter);
    }
}
