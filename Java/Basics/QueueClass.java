import java.util.Scanner;

public class QueueClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the queue you want to make:");
        int size;
        size = sc.nextInt();
        Queue q = new Queue(size);
        int n;
        do {
            System.out.println("Which operation you want to perform:");
            System.out.println("Press 1 - To enqueue");
            System.out.println("Press 2 - To dequeue");
            System.out.println("Press 3 - To display front element of the queue");
            System.out.println("Press 4 - To check if queue is full or not");
            System.out.println("Press 5 - To check if queue is empty or not");
            int operation;
            operation = sc.nextInt();
            switch (operation) {
                case 1:
                    System.out.println("Enter the key you want to insert");
                    int key;
                    key = sc.nextInt();
                    q.enqueue(key);
                    break;
                case 2:
                    q.dequeu();
                    break;
                case 3:
                    System.out.println(q.front());
                    break;
                case 4:
                    System.out.println(q.isFull());
                    break;
                case 5:
                    System.out.println(q.isEmpty());
                    break;
            }
            System.out.println("If you want to perform more operation , then press 1 else 0:");
            n = sc.nextInt();

        } while (n == 1);

    }
}
