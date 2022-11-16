import java.util.Scanner;

public class Time {
    private int hours;
    private int minutes;
    private int seconds;

    public void input() {
        Scanner sc = new Scanner(System.in);
        System.err.println("Enter the hours:");
        hours = sc.nextInt();
        System.err.println("Enter the minutes:");
        minutes = sc.nextInt();
        System.err.println("Enter the seconds:");
        seconds = sc.nextInt();
    }

    public void add(Time t2) {
        int seconds = 0;
        int minutes = 0;
        int hours = 0;
        if (this.seconds + t2.seconds > 60) {
            seconds = this.seconds + t2.seconds - 60;
            minutes += 1;
        } else {
            seconds = this.seconds + t2.seconds;
        }
        System.out.println("Minutes" + minutes);

        if ((this.minutes + t2.minutes + minutes) > 60) {
            minutes += this.minutes + t2.minutes - 60;
            hours += 1;
        } else {
            minutes += this.minutes + t2.minutes;
        }
        System.out.println("Hours" + hours);
        hours += this.hours + t2.hours;

        System.out.println(hours + ":" + minutes + ":" + seconds);
    }

    public void subtract(Time t2) {
        int hours = this.hours - t2.hours;
        int minutes = this.minutes - t2.minutes;
        int seconds = this.seconds - t2.seconds;
        System.out.println(hours + ":" + minutes + ":" + seconds);
    }

    public void display() {
        System.out.println(hours);
        System.out.println(minutes);
        System.out.println(seconds);
    }

}
