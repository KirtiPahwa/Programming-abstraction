import java.util.Scanner;

public class Simple2 {

    public static void main(String[] args) {
        int n;
        System.out.println("Enter the size of the array");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        System.out.println("Array elements:");
        for (int i = 0; i < n; i++) {
            System.out.println(array[i]);
        }
        sc.close();
    }
}
