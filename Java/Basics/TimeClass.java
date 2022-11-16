public class TimeClass {

    public static void main(String[] args) {
        Time t1 = new Time();
        t1.input();
        Time t2 = new Time();
        t2.input();
        t1.add(t2);
        t1.subtract(t2);
    }

}