#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {0, 9, 8};
    int arr1[] = {0, 9, 8};

    cout << sizeof(arr) << endl;
    cout << &arr << endl; // base address
    cout << *arr << endl;
    cout << *(arr + 1) << endl;
    cout << arr << endl;
    cout << &arr << endl;
    cout << arr + 1 << endl;

    cout << sizeof(arr1) << endl;
    return 0;
}