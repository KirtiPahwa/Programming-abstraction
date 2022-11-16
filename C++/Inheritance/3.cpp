#include <iostream>
using namespace std;
// multiple inheritance
class A
{
public:
    A()
    {
        cout << "Default Constructor of A" << endl;
    }
    void a()
    {
        cout << "a";
    }
};
class B
{
public:
    B()
    {
        cout << "Default Constructor of B" << endl;
    }
    void a()
    {
        cout << "b";
    }
};
class C : private B, public A
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
    // obj.a(); //ambigious
    obj.A::a();

    return 0;
}