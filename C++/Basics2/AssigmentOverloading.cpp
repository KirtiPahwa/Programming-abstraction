/*
Copy assigment operator defines the behavior when an object is copied using the assigment operator=.

Copy Constructor vs Assigment:
Aopy construcor creates a new object(constructor).

An assingment operator assigns a value to an existing object.
An assingment opearator is always called on an object that has already been constructed.

Automatic Assigment Operator:
if an assigment operator in not provided, the c++ compiler provied an automatic assigment operator.
The automatic assignment operaor will copy the contents of all member variables.

Custom Assigment Operator:
A custom assigment operator is:
- Is a public member function of the class.
- Has the function name opertor=.
- Has a return value of a reference of the class type.
- Has exactly one argument- the argument must be const reference of the class type.
Example: Cube& constructor::operator=(const Cube& obj){}

*/

#include <iostream>
using namespace std;
class Cube
{
public:
    int len;
    Cube()
    {
        len = 1;
        cout << "Default constructor invoked!!" << endl;
    }
    Cube(const Cube &obj)
    {
        len = obj.len;
        cout << "Copy constructor invoked!!" << endl;
    }
    Cube &operator=(const Cube &obj)
    {
        len = obj.len;
        cout << "Assignment operator invoked!!" << endl;
        return *this;
    }
};
int main()
{
    Cube c;      // default
    Cube myCube; // default
    myCube = c;  // assigment operator

    return 0;
}
