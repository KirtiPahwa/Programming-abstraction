#include <iostream>
using namespace std;

int main()
{

    // 32 bit:pointer size is 4 bytes
    // 64 bit:pointer size is 8 bytes
    int b = 8;
    int *a = &b;
    int *c = nullptr;
    // cout << a << endl;
    // cout << c << endl; //gives 0
    // cout << *c << endl; // gives segmentation fault

    int *ptr; // not defined  //call wild pointer
    // cout << ptr << endl;   // segmentation fault on deferencing
    int *ptr2 = NULL; // value :0 //null pointer
    // cout << ptr2 << endl;  // gives 0
    // cout << *ptr2 << endl; // gives segmentation fault

    // void pointers cannt be deferenced
    int var = 6;
    char alpha = '3';
    void *ptr3;
    ptr3 = &var;
    cout << &var << endl;
    cout << (int *)var << endl;
    ptr3 = &alpha;
    cout << (char *)ptr3 << endl;

    return 0;
}