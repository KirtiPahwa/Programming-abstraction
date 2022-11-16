import java.util.Scanner;

public class StackClass {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        String choice = "y";
        int ch, data;

        Stack first = new Stack();
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Enter Your Choice");
            System.out.println("1. Push");
            System.out.println("2. POP");
            System.out.println("3. Display");
            ch = sc.nextInt();

            switch (ch) {
                case 1:
                    if (!first.Isfull()) {
                        System.out.println("Inserting the value");
                        System.out.println("Enter value");
                        data = sc.nextInt();
                        first.push(data);
                    } else {
                        System.out.println("Stack is full");
                    }
                    break;

                case 2:
                    if (!first.Isemplty()) {
                        System.out.println("Poping the value");
                        data = first.pop();
                        System.out.println("Data===>" + data);
                    } else {
                        System.out.println("Emplty Stack");
                    }
                    break;
                case 3:
                    if (!first.Isemplty()) {
                        System.out.println(" Displaying the value");
                        first.display();
                    } else {
                        System.out.println("Emplty Stack");
                    }
                    break;

            }

            System.out.println("Do you want to continue<y/n");
            choice = sc.next();
        } while (choice.equals("y"));

    }

}
