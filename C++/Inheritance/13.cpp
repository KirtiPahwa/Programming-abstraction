#include <iostream>
using namespace std;
class Base
{
public:
    int b;
    virtual void show() // if we use virtual keyword then derived function's show() will call
    {
        cout << "Show() Base Class" << endl;
        cout << "b= " << b << endl;
    }
};
class Derived : public Base
{
public:
    int d;
    void show()
    {
        Base::show();
        cout << "Show() Derived class" << endl;
        cout << "b= " << b << endl;
        cout << "d= " << d << endl;
    }
};

int main()
{
    Derived a;
    a.d = 5;
    a.b = 6;
    a.show(); // call show() of derived class
    // a.Base::show(); // call show() of base class

    Derived Dobj;
    Base *B = &Dobj; // call show function of base class not object class

    Base *C = new Derived(); // c is holding derived class object but accessibility is only of base class data members
    // Derived *D = new Base(); // not possible to point Base class object to derived class

    B->show(); // will call show() function fo basse class
    C->show();

    cout << B->d << endl;

    // we can only give reference of derived class to base class pointer . vice versa is not possible (cann't give reference of base class to derived class pointer).
    // Base* B=new Derived();
    // if derived class reference is passed to base pointer . Then function show() will be call of base class not derived class . It is just pointing to derived class but pointer is of base class. Means derived class data members are not accessible through this pointer
    // If we want to call show() function of derived class then we have to use virtual keyword before writing the show() function . Virtual keyword binds Base class pointer with derived class object. Bydefault Base class pointer is just binded with base class itself.Now, Base class pointer which is binded to derived class object can access derived class data members

    return 0;
}