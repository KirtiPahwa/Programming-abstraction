// #include <iostream>
// using namespace std;

// int sum(int a, int b)
// {
//     return a + b;
// }
// float sum(float a, float b)
// {
//     return a + b;
// }

// int main()
// {
//     return 0;
// }
// This is equivalent to the below code

#include <iostream>
using namespace std;

template <class typeName>
typeName output(typeName a, typeName b)
{
    return a + b;
}
template <class T, int N> // only integral value is allowed
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    return 0;
}
