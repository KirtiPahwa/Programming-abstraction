#include <iostream>
using namespace std;

int add(int x, int y)
{
    return x + y;
}
int add(int x, int y, int z)
{
    return x + y + z;
}

int sub(int x, int y)
{
    return x - y;
}

int operation(int x, int y, int (*function)(int, int)) // 3rd argument is a prototype and it should match with prototype of function passed as argument
{
    int g;
    g = (*function)(x, y);
    return g;
}
int operation(int x, int y, int z, int (*function)(int, int, int)) // 3rd argument is a (function pointer) prototype and it should match with prototype of function passed as argument
{
    int g;
    g = (*function)(x, y, z);
    return g;
}

int main()
{
    int a = 6, b = 9, c = 5;
    cout << "Add: " << operation(a, b, add) << endl; // a and b are pass by value and add function is pass by reference
    cout << "Sub: " << operation(a, b, sub) << endl;
    cout << "Add: " << operation(a, b, c, add) << endl;

    return 0;
}