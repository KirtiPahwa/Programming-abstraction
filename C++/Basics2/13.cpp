#include <iostream>
typedef unsigned int Uinteger; // assigned a alias for already existing data type as like define (difference is : in define you can put name for some code and also you can define alias to a number  )
#define one 1;
using namespace std;

int main()
{
    Uinteger a, b;
    b = one + 1;
    cout << (b) << endl;
    return 0;
}