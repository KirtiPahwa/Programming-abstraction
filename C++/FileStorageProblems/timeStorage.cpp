#include <iostream>
using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void display()
    {
        cout << "Date is: " << this->day << "-" << this->month << "-" << this->year << endl;
    }
};
class Time
{
public:
    int hours;
    int minutes;
    Time()
    {
        hours = 0;
        minutes = 0;
    }
    Time(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    void convert()
    {
        cout << "Minutes are: " << this->hours * 60 + this->minutes << endl;
    }

    void display()
    {
        cout << "Time is: " << this->hours << ":" << this->minutes << endl;
    }
};

class DateTime
{
    Time time;
    Date date;

public:
    DateTime(int d, int month, int y, int h, int m)
    {
        date.day = d;
        date.month = month;
        date.year = y;
        time.hours = h;
        time.minutes = m;
    }
    void difference(DateTime b)
    {
        cout << "Difference between dates of two dateTime objects is : " << abs(this->date.day - b.date.day) << " days " << abs(this->date.month - b.date.month) << " months " << abs(this->date.year - b.date.year) << " years " << endl;
        cout << "Difference between timings of two dateTime objects is: " << abs(this->time.hours - b.time.hours) << " hours " << abs(this->time.minutes - b.time.minutes) << endl;
    }
};
int main()
{
    DateTime a(20, 4, 2022, 4, 12);
    DateTime b(10, 2, 2020, 2, 40);
    a.difference(b);

    return 0;
}

/*
A classes Date &  Time whcih will have following member variable:
Date:
a) day
b) month
c) year
Time:
a) hours
b) minutes.

create their respective member function like
a. intialize the members variables of both classes
b. Display the date as well as time
c. conversion of hours and minutes to minutes.

Also you are instructed to perform the aggregation of both the classes in DateTime Class to work it as a single object with an add on feature to find a difference between two date time objects

*/