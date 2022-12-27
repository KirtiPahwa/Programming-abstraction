

/*
A special constructor that exists to make a copy of an existing object.

Automatic copy constructor:
If we do not provide copy constructor, the c++ compiler provides an automatic copy constructor for our class for free.
The automatic copy constructor will copy the contents of all member variables.

Custom copy constructor:
A custom copy constructor is:
- A class constructor
- Has exactly one argument --- The argument must be const reference of the same type as the class.
Eg., Cube::Cube(const Cube& obj){
 }

Copy Constructor Invocation:
Often , copy constructors are invoked automatically:
-Passing an object as a parameter(by value).
-Returning an object from a function (by value).
-Initializing a new object.

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
        cout
            << "Copy constructor invoked!!" << endl;
    }
};
Cube foo(Cube cube)
{
    return cube;
}

Cube foo2()
{
    Cube c;   // default constructor
    return c; // copy constructor (bcz the obj we are returning is going to main means return type is cube and we are returnig the obj c which is assigning to Cube return type to send it to the main function.)
}
int main()
{
    // Cube c;
    // Cube c1 = c; // copy constructor
    // Cube c3;     // default constructor
    // c3 = c;      // assigment operator (not copy constructor will be invoked)(bcz we are just copying/assignment 2 existing object. we are not doing any contruction)

    // 1st
    // Cube c;           // default constructor
    // foo(c);           // copy constructor (bcz we are assigning c object to the parameters object)

    // 2nd
    Cube c2 = foo2(); // copy constructor (foo is returning value and assignning it to the c2)//here returned object from foo2() is assigning to the Cube c2.
    return 0;
}
