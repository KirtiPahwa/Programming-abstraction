/*
Virtual function rules:
the virtual functions must be members of some class.
Cannot be static member
accessed by using an object pointers.
Can be a friend of another classs.
VF in a base class must be derfined m even thoug it may not be used.(code block should be there).
the prototyles o base classs verion and all th derived class must be indentical, otherwise treated as overloads.(and if prototype si same then its called overriding)
while the base pointer points to any types of derived object,but vice versa will not allow to access the object of base clas.
-if a birtual function is defined in the base class it need not be necessarily redefined in ther derived clas. In such case the call wil invoke the base function itself.

*/

/*
Abstract base classes;
-classes that can only be used as base classes , and thus are allowed to have virtual member functions without definition.
e.g. virtual void display()=0//pure virtual functios. equivalent to --int* ptr=0//null pointer.
- classes that contain at least one pure virtual function are known as abstract base classes.
-abstract classs can not be used to declrre an object of itself.
 */

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
    virtual int area() = 0; // this need to be defined in derived classes
};
class Rectangle : public Polygon
{
public:
    int area()
    {
        cout << "Area of Rectangle" << endl;
        return width * height;
    }
};
class Triangle : public Polygon
{
public:
    int area()
    {
        cout << "Area of Triangle" << endl;
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
