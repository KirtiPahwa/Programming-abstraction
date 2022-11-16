import java.util.Scanner;

public class PatternsClass {
    public static void main(String args[]) {
        System.out.println("Enter the number :");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // as nextInt leaves the enter or newline at the end , so our next() or
                       // nextLine() can take the enter or newline character just . so it will not take
                       // the inputted string . so we have to write the nextline() which will take the
                       // newline just and then another nextline that will take inputted string
        char ch = sc.next().charAt(0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                System.out.print(" ");
            }

            for (int j = 1; j <= i; j++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < n - i + 1; j++) {
                System.out.print(" ");
            }

            for (int j = 1; j <= i; j++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }

    }
}
