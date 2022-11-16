class Stack {
    private int num[] = new int[5];
    private int top;

    Stack() {
        top = -1;
    }

    public void push(int x) {
        num[++top] = x;

    }

    public int pop() {
        return num[top--];

    }

    public boolean Isfull() {
        if (top >= 4)
            return true;
        else
            return false;

    }

    public boolean Isemplty() {
        if (top == -1)
            return true;
        else
            return false;

    }

    public void display() {

        for (int i = top; i >= 0; i--)
            System.out.println(num[i]);
    }

}
