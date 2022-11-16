#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    int *ptr = &x;
    const int *ptr2 = &x;       // non-const pointer to const int ---we cann't change the value of x through non-const pointer
    int *const ptr3 = &x;       // const pointer to non-const int ---we cann't change the address of the ptr pointing to the variable
    const int *const ptr4 = &x; // const pointer to const int-- we cann't change the address and value of x

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value pointer by ptr " << *ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;

    *ptr = 18;
    cout << "Updated value of x is: " << x << endl;
    *ptr2 = 18; // giving compilation  error as integer is of const type so pointer cannt change the value of x
    *ptr3 = &z; // giving compilation error as pointer is of const type and it cannt be pointed to any other variable
    *ptr4 = 13;
    *ptr4 = &z;

    cout << "Changing the reference of ptr" << endl;
    int z = 10;
    ptr = &z;
    cout << "Value of z: " << z << endl;
    cout << "Address of z: " << &z << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value pointer by ptr " << *ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;

    const

        return 0;
}