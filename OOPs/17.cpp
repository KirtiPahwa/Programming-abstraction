#include <iostream>
using namespace std;
// unary prefix/postfix operator overloading
class num
{
    int x;
    float y;

public:
    num()
    {
        x = 0;
        y = 0;
    }
    void operator++()
    {
        x = x + 1; // for prefix operator overloading
        y = y + 1;
    }
    void operator++(int a)
    {
        x = x + 1; // for postfix operator overloading (this a paramter is none and we even dont pass while calling . This is just to declare postfix)
        y = y + 1;
    }
    void print()
    {
        cout << "Value of the invoking object is: " << x << endl;
        cout << "Value of the invoking object is: " << y << endl;
    }
};

int main()
{
    num n;
    n.print();
    ++n;
    n.print();
    n++;
    n.print();

    return 0;
}