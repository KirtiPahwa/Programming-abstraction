#include <iostream>
#include <cstring>
using namespace std;
enum alphabets
{
    a,
    b,
    c
};
int main()
{

    // cout << a << " " << b << " " << c << endl;
    // // a = 1; //we cann't modify the enum after declaration
    // cout << a << " " << b << " " << c << endl;

    char a[100];
    // a = "kirti"; we cann't do this
    /*

    int arr[3];
    arr = {1, 9, 4};
    We cann't do this also because arrays are non modifiable once intialised.

    Strictly speaking, an array is not a pointer! And an array ( base address of the array ) cant be a modifiable lvalue. ie it cannot appear on the left hand side of an assignment operator.Arrays decay into pointers only in certain circumstances. Read this SO post to learn when arrays decay into pointers. Here is one more nice article which explains the differences between arrays and pointers

Also read about lvalues and rvalues here so that you get an idea of things which cannot appear on the LHS of =

char a[10]="iqbal";  // it works

In this case, internally what happens is

a[0] = 'i';
a[1] = 'q';
 .
 .
a[5] = '\0';
So everything is fine as array[i] is a modifiable lvalue.

a="iqbal"; // does not work

Internally, this is roughly equivalent to

0x60000(Address of a, but is a simple number here ) = Address of "iqbal"
This is wrong as we cannot assign something to a number.



     */
    /*  alternate approach to do the same work */
    strcpy(a, "Saving");
    cout << a << endl;

    return 0;
}