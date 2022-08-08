#include <iostream>
using namespace std;
class student
{
    string name;
    float age;

public:
    student()
    {
        cout << "Constructor is called" << endl;
    }
    student(string name, float age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
    void *operator new(size_t size)
    {
        cout << "Overloading new operator with size: " << size << endl;
        void *p = ::operator new(size); //::is used to call global variable  //we are calling to default new operator as we cannot overwrite it // all we can do is to add some extra lines or code while calling new operator
        return p;
    }
    void operator delete(void *p)
    {
        cout << "Overlaoding delete opertor" << endl;
        free(p); // cannot call delete operator again else recursive calls can be there
    }
};
int main()
{
    student *p = new student("C Plus Plus", 4);
    p->display();
    delete p;

    return 0;
}