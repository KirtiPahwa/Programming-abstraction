#include <iostream>
using namespace std;
template <class T>
// default arguments
T add(T a, T b, T c = 0, T d = 0)
{
    cout << a << " " << b << " " << c << " " << d << endl;
    return a + b + c;
}
int main()
{
    cout << add<int>(2, 4, 3) << endl;
    return 0;
}