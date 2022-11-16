import java.util.Scanner;

public class ConversionsClass {
    public static void BinaryConverter(int n) {
        int ans = 0;
        int i = 1;
        while (n != 0) {
            ans += (n % 2) * i;
            n = n / 2;
            i *= 10;
        }
        System.out.println("The binary of the n is:" + ans);
    }

    public static void OctalConverter(int n) {
        int ans = 0;
        int i = 1;
        while (n != 0) {
            ans += (n % 8) * i;
            n = n / 8;
            i *= 10;
        }
        System.out.println("The octal conversion of the number " + ans);
    }

    public static void Hexadecimal(int n) {
        String ans = "";
        while (n != 0) {
            int rem = n % 16;
            switch (rem) {
                case 10:
                    ans = 'A' + ans;
                    break;
                case 11:
                    ans = 'B' + ans;
                    break;
                case 12:
                    ans = 'C' + ans;
                    break;
                case 13:
                    ans = 'D' + ans;
                case 14:
                    ans = 'E' + ans;
                    break;
                case 15:
                    ans = 'F' + ans;
                    break;
                default:
                    ans = (char) (rem + '0') + ans; // 4+48=52 which is ascii digit of the number 4 //no need to do this
                                                    // because in java , we can concatenate string to int without using
                                                    // any function

            }
            n /= 16;
        }
        System.out.println("The hexadecimal of the number is:" + ans);

    }

    public static void main(String args[]) {
        System.out.println("Enter the number");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println("Which operation you want to perform?");
        System.out.println("Press 1 - For converting into Binary");
        System.out.println("Press 2 - For converting into Octal");
        System.out.println("Press 3 - For converting into Hexadecimal");
        int operation = sc.nextInt();
        switch (operation) {
            case 1:
                BinaryConverter(n);
                break;
            case 2:
                OctalConverter(n);
                break;
            case 3:
                Hexadecimal(n);
                break;

        }

    }
}
