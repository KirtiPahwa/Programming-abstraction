#include <iostream>
using namespace std;
//
class A
{

public:
    int a;
    A(int val)
    {
        a = val;
        cout << "Default Constructor of A " << a << endl;
    }
};
class B : public A
{
public:
    int a;
    B(int val) : A(val)
    {
        a = val;
        cout << "Default Constructor of B " << a << endl;
    }
};
class C : private B
{
public:
    C(int val) : B(val)
    {
        cout << "Default Constructor of C" << endl;
    }
};

int main()
{
    C obj(5);

    return 0;
}