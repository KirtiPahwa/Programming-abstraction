import java.util.Scanner;

public class ComplexNumber {
    private int real;
    private int img;

    public void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the real part of the complex Number");
        real = sc.nextInt();
        System.out.println("Enter the imaginery part of the complex Number");
        img = sc.nextInt();
        // sc.close();
    }

    public void display() {
        // int r = this.real > 0 ? this.real : -1 * this.real;
        int i = this.img > 0 ? 1 : -1;
        System.out.println("Complex Number is:" + this.real + (i > 0 ? "+" : "") + this.img + "i");
    }

    public ComplexNumber Add(ComplexNumber a) {
        ComplexNumber ans = new ComplexNumber();
        ans.real = this.real + a.real;
        ans.img = this.img + a.img;
        return ans;

    }

    public ComplexNumber Subtract(ComplexNumber a) {
        ComplexNumber ans = new ComplexNumber();
        ans.real = this.real - a.real;
        ans.img = this.img - a.img;
        return ans;
    }

    public ComplexNumber Multiply(ComplexNumber a) {
        ComplexNumber ans = new ComplexNumber();
        ans.img = (this.real * a.real) + (this.img * a.real);
        ans.real = this.real * a.real - this.img * this.img;
        return ans;
    }

}