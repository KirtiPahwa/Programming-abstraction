#include <iostream>
using namespace std;
// Inheritance: the process of deriving a new clas from and existing class is called inheritance
// Base-parent class and Derived-child class
// Syntax: class derived_class:public base_class_name,.....  (in this access modifier is used for defining child class's variables access modifier)
// We can do multiple inheritance in c++ not in java

// Inheritance Type:
// 1. single inheritance   A-parent and B-child
// 2. Multiple inheritance  A-parent, B-parent and C-child
// 3. Heirarichal inheritacne A-parent, B-child , C-child, D-child
// 4. Multilevel iheritance A-parent1, B-parent2(parent of c and child of a), C-child
// 5. Hybrid or virtual base class

// Public-can use anywhere in any child class
// Private-can be use within same class only and cann't be inherited further
// Protected-can be use within the same class (not even in main function) and can also use in child classes

class A
{
public:
    int publicVal;

private:
    int privateVal;

protected:
    int protectedVal;
};
class B : public A
{

    // Here public:publicVal and protected:protectedVal
public:
    void setProtectedVal(int a)
    {
        protectedVal = a;
    }
    int getProtectedVal()
    {
        return protectedVal;
    }

    void display()
    {
        cout << "Value of public Val: " << publicVal << endl;
    }
};

class C : protected A
{
    // Here   protected:protectedVal,publicVal
public:
    void setProtectedVal(int a)
    {
        protectedVal = a;
    }
    int getProtectedVal()
    {
        return protectedVal;
    }
    void setPublicVal(int a)
    {
        publicVal = a;
    }
    int getPublicVal()
    {
        return publicVal;
    }
};

class D : private A
{
    // Here   private:protectedVal,publicVal
public:
    void setProtectedVal(int a)
    {
        protectedVal = a;
    }
    int getProtectedVal()
    {
        return protectedVal;
    }
    void setPublicVal(int a)
    {
        publicVal = a;
    }
    int getPublicVal()
    {
        return publicVal;
    }
};

int main()
{
    B obj1;
    obj1.publicVal = 5;
    obj1.setProtectedVal(6);
    cout << "Value of protected val : " << obj1.getProtectedVal() << endl;

    C obj2;
    // cout << obj2.publicVal << endl; //inaccessible

    return 0;
}