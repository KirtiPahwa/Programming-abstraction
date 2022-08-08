#include <iostream>
using namespace std;
// we have to give the argument in child class to pass it to the base class
class A
{

public:
    int a;
    A()
    {
        cout << "Default constructor of A" << endl;
    }
    A(int val)
    {
        a = val;
        cout << "Constructor of A " << a << endl;
    }
};
class B : public A
{
public:
    int a;
    B()
    {
        cout << "Default constructor" << endl;
    }
    B(int val, int val2) : A(val2)
    {
        a = val;
        cout << "Explicit Constructor of B " << a << endl;
    }
};
class C : private B
{
public:
    C()
    {
        cout << "Default constructor" << endl;
    }
    C(int val, int val2) : B(val, val2)
    {
        cout << "Explicit Constructor of C" << endl;
    }
};

int main()
{
    C obj(5, 6);

    return 0;
}