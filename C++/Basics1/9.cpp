#include <iostream>
using namespace std;
void output(int, long); // 1
// void output(double, int);  // 2   1&2 gives error as overloaded function matches the arguments list. Because output(2,4) : 2 says to go in 1'st output as 2 resembles int more than double . And then 4 says to go in 2nd output as 4 matches more with int (in 2nd) not long (in 1st)
void output(double, double); // 3   1&3 gives no error . So they are overloaded function as 2 says to go int 1st and 4 can go into any out of 1 and 3 that is long & double . So we will go according to 2 thats in 1st
int main()
{
    output(2, 4); // here 2 is int out of
    return 0;
}
void output(int a, long b)
{
    cout << "float output" << endl;
    cout << a << " " << b << endl;
}
// void output(double a, int b)
// {
//     cout << "double output" << endl;
//     cout << a << " " << b << endl;
// }
void output(double a, double b)
{
    cout << "double int" << endl;
}