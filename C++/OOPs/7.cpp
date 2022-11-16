#include <iostream>
using namespace std;
class ArithmeticOps
{
private:
    int fVal, sVal;

public:
    ArithmeticOps(int a, int b) // constructor can only be declared  publicly   //if we don't define the constructor then default parameter is called which doesn't have any parameters
    {
        fVal = a;
        sVal = b;
    }
    void setfVal(int, int);
    int getfVal();
    int getsVal();
    int add();
    int sub();
};
int ArithmeticOps::getfVal()
{
    return fVal;
}
void ArithmeticOps::setfVal(int a, int b) // scope resolution operator
{

    fVal = a;
    sVal = b;
}
int ArithmeticOps::add()
{
    return fVal + sVal;
}
int ArithmeticOps::sub()
{
    return fVal - sVal;
}
int main()
{
    ArithmeticOps a(2, 3);
    a.setfVal(2, 3);
    cout << a.getfVal() << endl;

    return 0;
}