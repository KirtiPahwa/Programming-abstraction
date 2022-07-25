#include <iostream>
using namespace std;
class Rectangle
{
    int width, height;

public:
    Rectangle() {}
    Rectangle(int x, int y) : width(x), height(y) {} // assigning width=x and height=y
    int area() { return width * height; }
    int area2() const { return width * height; }   // if you want to use it with const objects then area should also be const
    friend Rectangle duplicate(const Rectangle &); // friend function prototype where friend function return rectangle object and we are passing the address of Rectangle object as an argument
    friend Rectangle compare(const Rectangle &, const Rectangle &);
};
Rectangle duplicate(const Rectangle &param) // param is parameter of object of rectangle class
{
    Rectangle res;
    res.width = param.width * 2;
    res.height = param.height * 2;
    return res;
}
Rectangle compare(const Rectangle &param1, const Rectangle &param2)
{
    if (param1.width * param1.height >= param2.height * param2.width)
    {
        return param1;
    }
    else
    {
        return param2;
    }
}
Rectangle compare2(const Rectangle &param1, const Rectangle &param2)
{
    const Rectangle &res = param1.area2() >= param2.area2() ? param1 : param2;
    return res;
}

int main()
{
    // Friend function:- a non-member function can access the private and protected memeber of a class .
    // It is not in the class to which it has been declared as friend,therefore cannot be called using object.
    // object passed as arguments.
    // cannot access the member names directly instead use an object to access

    Rectangle foo;
    Rectangle bar(2, 3);
    foo = duplicate(bar);
    cout << foo.area() << endl;

    Rectangle a1(2, 3);
    Rectangle a2(3, 4);
    Rectangle obj;
    obj = compare(a1, a2);
    cout << obj.area() << endl;

    return 0;
}