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
};
class B
{
public:
    B()
    {
        cout << "Default Constructor of B" << endl;
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

    return 0;
}