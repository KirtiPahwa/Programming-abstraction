#include <iostream>
using namespace std;
// heirarichal inheritance
// the base class's constructors are called first in the order of inheritance and then the derived class's constructor.
// all the upper class constructors are executed when an instance of bottom most child class is created
class A
{
public:
    A()
    {
        cout << "Default Constructor of A" << endl;
    }
};
class B : public A
{
public:
    B()
    {
        cout << "Default Constructor of B" << endl;
    }
};
class C : public B
{
public:
    C()
    {
        cout << "Default Constructor of C" << endl;
    }
};

int main()
{
    C obj;

    return 0;
}