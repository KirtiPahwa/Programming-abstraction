#include <iostream>
using namespace std;
// class Inches; // to use constructor of feet object which takes the object of inches as input . We did forward declaration because we have declared inches class after feet . So the solutin is to declare the inches class before but then we cann't make the constructor in inches and also while running the code it will ask for the memory of inches object which is declared as forward delclarationg which is not having any memory size . So it gives error again. So cannot interconversion of feet and inches at the same time.
class Feet
{
public:
    int feet;
    int inches;
    // Feet(Inches &i)
    // {
    //     feet = i.inches / 12;
    //     inches = i.inches % 12;
    // }
    Feet(int feet = 0, int inches = 0)
    {
        this->feet = feet;
        this->inches = inches;
    }
    void display()
    {
        cout << feet << "Feets and " << inches << " inches " << endl;
    }
};
class Inches
{
public:
    int inches;
    Inches(int feet = 0)
    {
        inches = feet * 12;
    }
    Inches(Feet &feet)
    {
        cout << "feet object" << endl;
        inches = feet.feet * 12 + feet.inches;
    }
    void display()
    {
        cout << "Inches: " << inches << endl;
    }
    void operator=(const Feet &feet)
    {
        cout << "Assignment operator overloading" << endl;
        inches = feet.feet * 12 + feet.inches;
    }
};

int main()
{
    Feet a(5, 6);
    Inches b(a);
    Inches c = Inches(a);

    Inches f = a; // call copy constructor therefore call feet object
    Inches e;
    e = a; // call assignment operator

    // Feet d = Feet(c);
    b.display();
    a.display();
    // c.display();
    // d.display();

    return 0;
}