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
class B
{
public:
    int a;
    B(int val)
    {
        a = val;
        cout << "Default Constructor of B " << a << endl;
    }
};
class C : private A, public B
{
public:
    C(int val) : A(val), B(val)
    {
        cout << "Default Constructor of C" << endl;
    }
};
class D : private B, public A
{
public:
    D(int val) : A(val), B(val)
    {
        cout << "Default Constructor of D" << endl;
    }
};
class E : private A, public B
{
public:
    E(int val, int val2) : A(val), B(val2)
    {
        cout << "Default Constructor of C" << endl;
    }
};

int main()
{
    C obj(5);
    cout << "D object" << endl;
    D obj1(7);
    cout << "E object" << endl;
    E obj2(6, 7);

    return 0;
}