#include <iostream>
using namespace std;
// Operators overloading
// allow to define user defined behaviour for the selected operator like +,-,etc.
// operator keyword is ued followed by the symbol of operator
// Syntax:type operator sign(parameters){body}
// it is beign done to allow the oerations to be performend ton the objects of the same type

// Operators that cannot be overloaded are:
// Class members access operator-[.,.*]
// Scope resolution cann't be overload (::)

// Rules:
// Only existingoperators can be overloaded
// operaor overload must have atlesas one operand that is of user deined type.
// we cannot change the basic meaning of the operator

class temp
{
    int a, b;

public:
    temp(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
        cout << "Default/overloaded constructor is called" << endl;
    }
    temp(temp &t)
    {
        a = t.a;
        b = t.b;
        cout << "Copy constructor is called" << endl;
    }
    void operator=(const temp &t)
    {
        this->a = t.a * 2;
        this->b = t.b * 2;
        cout << "Assignment operator overload is called" << endl;
    }
    temp operator+(const temp &t)
    {
        temp newTempObj;
        newTempObj.a = this->a + t.a * 2;
        newTempObj.b = this->b + t.b * 2;
        cout << "Addition operator overload is called" << endl;
        return newTempObj;
    }
    void display()
    {
        cout << this->a << "  " << this->b << endl;
    }
};

int main()
{
    temp obj1;             // default constructor
    temp obj2;             // default
    temp tobj(obj2);       // copy constructor will be call
    temp tobj1 = obj2;     // copy constructor will be call bcz we are intialiseing the obj at the time of declareing the object
    obj1 = obj2;           // assignment operator called
    obj2.operator=(tobj1); // assigment operator called
    // temp tobj1;
    temp addResult;
    addResult = tobj1.operator+(obj2);
    tobj1.operator=(obj2);
    addResult.display();

    // We cannot overload the operator + which is taking int and int. We can make other function overload for different type of the arguments

    return 0;
}