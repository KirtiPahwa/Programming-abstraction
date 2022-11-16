import java.util.Scanner;

public class StringDemoClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any String");
        String str = sc.nextLine();
        int countWords = 1;
        int countChars = 0;
        int countVowels = 0;
        str = str.toLowerCase();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                countWords++;
            } else {
                countChars++;
            }
            char c = str.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                countVowels++;
            }

        }
        System.out.println("No. of words" + countWords);
        System.out.println("No. of characters" + countChars);
        System.out.println("No. of vowels" + countVowels);

    }
}
