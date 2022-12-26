#include <iostream>
using namespace std;

int main()
{

    // Puzzle1:
    int *x = new int; // x from the stack memory is pointing to any memrory in heap where intege will store.
    int &y = *x;      // y is alias for the memory which is in heap and is pointed by x variable in stack.  (if we do int &a=b; then it assign the address of b to a's adress. Means a and b both are pointing to the same memroy address.s)
    y = 4;
    // int &y = x;  //we cann't do that because y is int and x is a int* (pointer).
    cout << &x << endl;
    cout << x << endl;
    cout << *x << endl;
    cout << &y << endl;
    cout << y << endl;
    // cout << *y << endl; //give compile error as we are trying to deference the non pointer variable.

    /*Output:
    0x61ff08
0xf90fc8
4
0xf90fc8
4

    */

    // Puzzle2:
    int *p, *q;
    p = new int;
    q = p;
    *q = 8;
    cout << *p << endl;

    q = new int;
    *q = 9;
    cout << *p << endl;
    cout << *q << endl;

    /* output:
    8
    8
    9
    */

    //    Puzzle3:
    int *z;
    int size = 3;
    z = new int[size];
    for (int i = 0; i < 3; i++)
    {
        z[i] = i + 3;
    }
    // will assin the value  3 , 4, 5 (from downward to upward)
    delete[] x;
    return 0;
}
