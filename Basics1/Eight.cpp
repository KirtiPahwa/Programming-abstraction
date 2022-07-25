#include <iostream>
using namespace std;
int main()
{
    int rollNO;
    int *rollNOPointer = &rollNO;
    rollNO = 5;
    cout << rollNO << endl;
    cout << rollNOPointer << endl;
    cout << *rollNOPointer << endl;
    //  the type of varilable and the pointer pointing to variable should be same .
    // The size of pointer is independent of the type of the variable pointing to it because pointer is storing to address not the value For eg./
    char a = 'f';
    char *p = &a;
    cout << sizeof(p) << endl;

    // NExt program
    int var = 6;
    int *ptr1 = &var;
    int *ptr2 = NULL;
    int *ptr3 = nullptr;
    // ptr2 = ptr1;
    cout << ptr2 << endl;  // will print 0 means pointing to null value
    cout << *ptr2 << endl; // we cann't deference to a pointer pointing to null
    return 0;
}