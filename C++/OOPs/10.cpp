#include <iostream>
using namespace std;
class Timetrack
{
    int hours;
    int minutes;

public:
    void inputTime(int, int);
    int showTime();
    friend void totalTime(const Timetrack &, const Timetrack &); // A friend function is a function that isn't a member of a class but has access to the class's private and protected members.
    friend void a();
};
void Timetrack::inputTime(int hours, int min)
{
    this->hours = hours;
    this->minutes = min;
};
int Timetrack::showTime()
{
    cout << this->hours << " hours and " << this->minutes << " minutes " << endl;
}
void a()
{
    cout << "hello" << endl;
}
void totalTime(const Timetrack &teamA, const Timetrack &teamB)
{
    int totalTime = teamA.hours + teamB.hours;
    int totalMinute = teamA.minutes + teamB.minutes;
    totalTime += (totalMinute / 60);
    totalMinute %= 60;
    cout << "Total time is " << totalTime << " hours and " << totalMinute << " minutes " << endl;
}
int main()
{
    Timetrack teamA, teamB;
    teamA.inputTime(3, 45);
    teamB.inputTime(4, 3);
    totalTime(teamA, teamB);

    return 0;
}