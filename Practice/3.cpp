#include <iostream>
#include <limits.h>
using namespace std;
struct Person
{
    string name;
    int date;
    int month;
    int year;
};
int main()
{
    cout << "Enter the no. of person" << endl;
    int n;
    cin >> n;
    Person p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of the person" << endl;
        cin >> p[i].name;
        cout << "Enter the date of birth just" << endl;
        cin >> p[i].date;
        cout << "Enter the month of birth just" << endl;
        cin >> p[i].month;
        cout << "Enter the year of birth just" << endl;
        cin >> p[i].year;
    }
    int mx = INT_MIN;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int age = (2022 - p[i].year) * 365;
        if (mx < age)
        {
            mx = age;
        }

        if (mn > age)
        {
            mn = age;
        }
        else if (mn == age)
        {
        }
        cout << "Age of the person" << i << " " << age / 365 << endl;
    }
    return 0;
}