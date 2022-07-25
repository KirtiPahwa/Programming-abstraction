#include <iostream>
using namespace std;
int main()
{
    //   Datatypes and their sizes
    cout << "Size of bool " << sizeof(bool) << endl;
    cout << "Size of char " << sizeof(char) << endl;
    cout << "Size of short " << sizeof(short) << endl;
    cout << "Size of int " << sizeof(int) << endl;
    cout << "Size of float " << sizeof(float) << endl;
    cout << "Size of long " << sizeof(long) << endl;
    cout << "Size of double " << sizeof(double) << endl;
    cout << "Size of long long " << sizeof(long long) << endl;
    cout << "Size of long double " << sizeof(long double) << endl;

    char a = 65;
    int b = a; // Implicit conversion

    double c = 4;
    int d = (int)c; // Explicit conversion

    return 0;
}