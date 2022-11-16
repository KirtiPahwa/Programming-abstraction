#include <iostream>
using namespace std;
class Polygon
{
protected:
    int width, height;

public:
    void set_values(int a, int b) // we make it works as constructor as abstract classes cannot have objects
    {
        width = a;
        height = b;
    }
    Polygon(int a, int b) // works as constructor
    {
        cout << "Constructor of Polygon" << endl;
        width = a;
        height = b;
    }
    void printarea()
    {
        cout << this->area() << endl; // this will call through derived class pointers
    }
    virtual int area() = 0; // this need to be defined in derived classes
    // can call the function with apporpriate reference
};
class Rectangle : public Polygon
{
public:
    Rectangle(int a, int b) : Polygon(a, b)
    {
        cout << "Constructor of Rectangle" << endl;
    }
    int area()
    {
        return width * height;
    }
};
class Triangle : public Polygon
{
public:
    Triangle(int a, int b) : Polygon(a, b)
    {
        cout << "Constructor of Rectangle" << endl;
    }
    int area()
    {
        return width * height;
    }
};
int main()
{

    // Dynamically memory allocation
    Polygon *p = new Rectangle(4, 5); // constructor call to base via derived //new create memory or object in heap
    Polygon *q = new Triangle(4, 5);  // constructor call to base via derived
    p->printarea();
    q->printarea();

    // release memory approprialtely
    delete p;
    delete q;

    return 0;
}
