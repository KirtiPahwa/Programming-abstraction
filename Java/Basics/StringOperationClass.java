public class StringOperationClass {
    public static void main(String args[]) {
        String name = new String("Kirti Pahwa");
        char temp[];
        temp = name.toCharArray();
        int i = 0;
        for (char x : temp) {
            i++;
        }
        System.out.println("Length of the string is " + i);
    }
}
