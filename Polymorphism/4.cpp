#include <iostream>
using namespace std;
// abstract class cpolygon
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
    Rectangle rect;                 // concept of aggregation
    Triangle trgl;                  // concept of aggregation
    Polygon *ppoly1 = &rect;        // Base class Polygon pointer and reference to rectangle
    Polygon *ppoly2 = &trgl;        // Base class Polygon pointer and reference to triangle
    ppoly2->set_values(4, 5);       // inherited from polygon to rectangle
    ppoly1->set_values(4, 5);       // inherited from polygon to triangle
    cout << ppoly1->area() << endl; // dynamically call based on the virtual function call "rect"
    cout << ppoly2->area() << endl; // dynamically call based on the virtual function call "trgl"
    return 0;
}
