#include <iostream>
using namespace std;
class Base
{
public:
    int b;
    virtual void show() // This virtual keyword does dynamic binding so now Base class pointer which is pointing to derived class pionter will be able to access the derived class members and if not found the particular data member in derived then look for them in base class . Without virtual keyword we cannot access derived class members with base class pointer which is referencing to the derived class object. Base classs pointer with virtual keyword gives dynamic binding to every level of inheritance
    {
        cout << "Show() Base Class" << endl;
        cout << "b = " << b << endl;
    }
};
class Derived : public Base
{
public:
    int d;
    void show()
    {
        cout << "Show() Derived Class" << endl;
        cout << "b = " << b << endl;
        cout << "d = " << d << endl;
    }
};
class Third : public Derived
{
public:
    int d;
    void show()
    {
        cout << "Show() Third Class" << endl;
        cout << "b = " << b << endl;
        cout << "d = " << d << endl;
    }
};
int main()
{
    // Derived a;
    // a.show();
    // a.Base::show();
    Base *bptr;
    Base baseObj;
    bptr = &baseObj; // we are able to point the base class pointer to object class because base class pointer is typecompatible
    bptr->b = 10;
    cout << "Right now Base class pointer pointing to Base class object" << endl;
    bptr->show();
    cout << baseObj.b << endl;
    Derived derivedObj;
    bptr = &derivedObj;
    bptr->b = 90;
    // bptr->d=90; //not allowed giving compile time error
    cout << "Right now Base class pointer pointing to Derived class object" << endl;
    bptr->show();
    cout << derivedObj.b << endl;
    Derived *dptr;
    dptr = &derivedObj;
    dptr->d = 300;
    dptr->show();
    Third thirdObj;
    bptr = &thirdObj;
    cout << "Right now Base class pointer pointing to Third class object" << endl;
    bptr->show();

    cout << "using the typecasting of derived class pointer on base class pointer" << endl;
    ((Derived *)bptr)->d = 40;
    ((Derived *)bptr)->show();
    return 0;
}

// Virtual member is a member function that can be reefined in a derived class, while preseerving its calling propertied through references.
// Non-irtula members can also be redefined in derived classes,but non-virtual members of derived classes cannot be accessed throuh a reference of the base clas.
// Virtual keyword does is to allow a member of a derived class