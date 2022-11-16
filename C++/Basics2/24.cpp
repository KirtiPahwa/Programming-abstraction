#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    char b = 'd';
    void *ptr;
    ptr = &a;
    char *ptr2 = &b;
    cout << (*ptr2) << endl;
    // cout << (*ptr) << endl;
    cout << sizeof(ptr) << endl;
    ptr = &b;
    cout << sizeof(ptr) << endl;

    return 0;
}