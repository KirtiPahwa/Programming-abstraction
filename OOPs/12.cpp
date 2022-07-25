#include <iostream>
using namespace std;
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
};

int main()
{
    temp obj1;
    temp obj2;
    temp tobj(obj2);   // copy constructor will be call
    temp tobj1 = obj2; // copy constructor will be call bcz we are intialiseing the obj at the time of declareing the object
    obj1 = obj2;       // assignment opertor       // no constructor will be called bcz we are assigning the values directly to the memory      // not copy constructor ......just copying the values as like assigning
                       //   copy consturctor : copy the constructor and address of the objects will be different.

    // A copy constructor is a member function that initializes an object using another object of the same class.
    // Copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.
    // But the assignment operator does not make new memory space. It uses the reference variable to point to the previous memory block.

        // Copy Constructor	Assignment Operator
    // The Copy constructor is basically an overloaded constructor	Assignment operator is basically an operator.
    // This initializes the new object with an already existing object	This assigns the value of one object to another object both of which are already exists.
    // Copy constructor is used when a new object is created with some existing object	This operator is used when we want to assign existing object to new object.
    // Both the objects uses separate memory locations.	One memory location is used but different reference variables are pointing to the same location.
    // If no copy constructor is defined in the class, the compiler provides one.	If the assignment operator is not overloaded then bitwise copy will be made

    return 0;
}