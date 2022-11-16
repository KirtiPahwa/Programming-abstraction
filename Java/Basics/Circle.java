import java.util.Scanner;

public class Circle {
    private float radius;
    private float area;
    private float circumference;

    public void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the radius of the circle:");
        radius = sc.nextFloat();
        sc.close();
    }

    public void calculate() {
        area = 22 * radius * radius / 7;
        circumference = 2 * 22 / 7 * radius;
    }

    public void display() {
        System.out.println("Radius=" + radius);
        System.out.println("Area=" + area);
        System.out.println("Circumference=" + circumference);
    }

}
