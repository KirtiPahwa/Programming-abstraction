#include <iostream>
using namespace std;
class Box
{
private:
    double length, breadth, height;

public:
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        length = l;
        breadth = b;
        height = h;
    }
    double Volume()
    {
        return length * breadth * height;
    }
    int compare(Box box)
    {
        return this->Volume() > box.Volume();
    }
    Box *compare2(Box box)
    {
        Box *b;
        if (this->Volume() > box.Volume())
        {
            b = this;
        }
        else
        {
            b = &box;
        }
        return b;
    }
};

int main()
{
    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);
    if (Box1.compare(Box2))
    {
        cout << "Box1 is greater" << endl;
    }
    else
    {
        cout << "Box2 is greater" << endl;
    }

    // cout<<Box

    //  this refers to invoking object here .
    // Invoking object are the objects that are calling the member function . For eg., Box b1;
    //                  b1.area()
    //                  so here b1 object is the invoking object

    return 0;
}