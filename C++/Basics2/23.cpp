#include <iostream>
using namespace std;
int add(int x, int y)
{
    return x + y;
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

int main()
{
    int a = 6, b = 7;
    int (*operation[])(int, int) = {add, sub};
    cout << "Add: " << (*operation[0])(a, b) << endl;
    cout << "Sub: " << (*operation[1])(a, b) << endl;

    return 0;
}