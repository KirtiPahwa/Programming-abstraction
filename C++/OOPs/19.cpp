#include <iostream>
using namespace std;
class Distance
{
    int feet;
    int inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i)
    {
        feet = f;
        inches = i;
    }
    Distance(const Distance &d)
    {
        cout << "Copy constructor" << endl;
        Distance temp;
        feet = d.feet;
        inches = inches;
    }
    void operator=(const Distance &D)
    {
        feet = D.feet;
        inches = D.inches;
    }
    void displayDistance()
    {
        cout << feet << " feets " << inches << " inches " << endl;
    }
};

int main()
{
    Distance D1(11, 10), D2(5, 11);
    cout << "First Distance: ";
    D1.displayDistance();
    cout << "Second Distance: ";
    D2.displayDistance();
    D1 = D2; // assignment operator will be called
    cout << "First Distance: ";
    D1.displayDistance();
    Distance D3 = D2; // copy constructor
    D3.displayDistance();
    Distance D4(D3); // copy constructor
    D4.displayDistance();

    return 0;
}