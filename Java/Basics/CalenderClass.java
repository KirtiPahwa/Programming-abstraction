import java.util.Scanner;

public class CalenderClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the starting day:");
        int startingDay = sc.nextInt();
        System.out.println("Enter the Number of days:");
        int noOfDay = sc.nextInt();
        System.out.println("S  M  T  W  Th  F  S");
        for (int i = 0; i < startingDay; i++) {
            System.out.print("   ");
        }
        int k = 1;
        for (int i = startingDay; k <= noOfDay; i++) {
            if (i % 7 == 6) {
                System.out.println(k + "  ");
            } else {
                if (k <= 9) {
                    System.out.print(k + "  ");
                } else {
                    System.out.print(k + " ");
                }
            }
            k++;
        }
    }

}
