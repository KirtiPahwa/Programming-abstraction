import java.util.Scanner;
import java.util.Vector;
import java.lang.Math;
import java.math.BigInteger;

public class GcdClass {
    public void GcdMethod1(int a, int b) {
        int arrA[] = new int[a];
        int arrB[] = new int[b];
        int countA = 0;
        int countB = 0;
        for (int i = 1; i <= a; i++) {
            if (a % i == 0) {
                arrA[countA] = i;
                countA++;
            }
        }
        for (int i = 1; i <= b; i++) {
            if (b % i == 0) {
                arrB[countB] = i;
                countB++;
            }
        }
        int gcd = 0;
        for (int i = 0; i < countA; i++) {
            for (int j = 0; j < countB; j++) {
                if (arrA[i] == arrB[j]) {
                    gcd = arrA[i];
                }
            }
        }
        System.out.println("The GCD of two number " + a + " " + b + " is: " + gcd);

        // or
        // Vector<Integer> v = new Vector<Integer>();
        // v.add(a);
    }

    public void GcdMethod2(int a, int b) {
        Vector<Integer> vA = new Vector<Integer>();
        Vector<Integer> vB = new Vector<Integer>();

        int tempA = a;
        int tempB = b;
        int i = 2;
        while (tempA != 1) {
            if (tempA % i == 0) {
                tempA /= i;
                vA.add(i);
            } else {
                i++;
            }

        }
        i = 2;
        while (tempB != 1) {
            if (tempB % i == 0) {
                tempB /= i;
                vB.add(i);
            } else {
                i++;
            }

        }
        int gcd = 1;
        for (Integer j = 0; j < vA.size(); j++) {
            for (Integer k = 0; k < vB.size(); k++) {
                if (vA.get(j) == vB.get(k) && vA.get(j) != -1) {
                    gcd *= vA.get(j);
                    vB.set(k, -1);
                }

            }
        }
        System.out.println("The gcd of " + a + " " + b + " is: " + gcd);
    }

    public void GcdMethod3(int a, int b) {
        int smaller = a < b ? a : b;
        int larger = a > b ? a : b;
        while (larger % smaller != 0) {
            int temp = larger;
            larger = smaller;
            smaller = temp % smaller;

        }
        System.out.println(smaller);
    }

    public void GcdMethod4(int a, int b) {
        BigInteger b1 = BigInteger.valueOf(a);
        BigInteger b2 = BigInteger.valueOf(b);
        BigInteger gcd = b1.gcd(b2);

        System.out.println(gcd);

    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first number: ");
        int a = sc.nextInt();
        System.out.println("Enter the second number: ");
        int b = sc.nextInt();
        GcdClass obj = new GcdClass();
        obj.GcdMethod1(a, b);
        obj.GcdMethod2(a, b);
        obj.GcdMethod3(a, b);
        obj.GcdMethod4(a, b);

    }

}
