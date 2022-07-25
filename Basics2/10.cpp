#include <iostream>
using namespace std;

int main()
{
    enum color
    {
        red,
        black
    };
    cout << red << endl;
    cout << black << endl;

    enum suit
    {
        a = 3,
        b,
        c = 6,
        d,
        e = 3
    };
    cout << a << " " << b << " " << c << " " << d << " " << e << endl;

    return 0;
}