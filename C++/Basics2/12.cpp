#include <iostream>
using namespace std;

int main()
{

    enum operators
    {
        add,
        sub,
        div,
        mul
    };
    int func;
    cin >> func;
    switch (func)
    {
    case add:
        cout << "add" << endl;
        break;
    case sub:
        cout << "Sub" << endl;
        break;
    case div:
        cout << "div" << endl;
        break;
    case mul:
        cout << "multiply" << endl;
        break;
    }

    return 0;
}