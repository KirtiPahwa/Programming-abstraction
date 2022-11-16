public class Queue {
    private int data[];
    private int f, r;

    Queue(int size) {
        f = -1;
        r = -1;
        data = new int[size];
    }

    public boolean isEmpty() {
        if (f > r) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isFull() {

        if (r + 1 == data.length) {
            return true;
        } else {
            return false;
        }

    }

    public void enqueue(int key) {
        if (isFull()) {
            System.out.println("Queue  is full");
            return;
        }
        if (f == -1) {
            f++;
        }
        data[++r] = key;

    }

    public void dequeu() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        f++;
    }

    public int front() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        return data[f];
    }

}
