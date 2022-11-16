#include <iostream>
using namespace std;
class A
{
private:
    /* data */
public:
    static int s;
    A(/* args */);
    ~A();
};

A::A(/* args */)
{
    s++;
    cout << s << endl;
}

A::~A()
{
}
int A::s = 2;

int main()
{
    A a;
    cout << a.s << endl;
    A b;
    cout << b.s << endl;
    cout << a.s << endl;
    // So static variable is shared and if seconde object change it then changes of the static variable also reflects for first object

    return 0;
}