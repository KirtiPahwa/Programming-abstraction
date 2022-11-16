#include <iostream>
using namespace std;
void fun1(float a, int b)
{
    cout << "Func1" << endl;
}
void fun1(double a, int b)
{
    cout << "Func2" << endl;
}

int main()
{
    fun1(1.3f, 2);
}