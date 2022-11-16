#include <iostream>
using namespace std;
class Base
{
public:
    void display()
    {
        cout << "Base class display() function" << endl;
    }
    virtual void show()
    {
        cout << "Base class show() function" << endl;
    }
};

class Derived : public Base
{
public:
    void display()
    {
        cout << "Derived class display() function" << endl;
    }
    void show()
    {
        cout << "Derived class show() function" << endl;
    }
};
int main()
{
    Base *bptr;
    Base baseObj;
    Derived derivedObj;
    cout << "Base class pointer pointing to base class object" << endl;
    bptr = &baseObj;
    bptr->display();
    bptr->show();
    cout << "Base class pointer pointing to derived class object" << endl;
    bptr = &derivedObj;
    bptr->display();
    bptr->show();

    return 0;
}