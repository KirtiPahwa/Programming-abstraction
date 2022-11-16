#include <iostream>
using namespace std;

int main()
{
    // for (int i = 0; i < 5; i++)
    //     if (i < 5)
    //         cout << "Hello" << endl;

    int a = 5, b = 6, c, d;
    c = a, b;      // first element will be assigned
    d = (a, b, c); // last element will be assigned
    cout << a << " " << b << endl;

    cout << c << " " << d << endl;

    return 0;
}