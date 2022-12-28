#include <iostream>
using namespace std;
//you can also intialise the variables of the  class while calling constructor of the  class itself
class A
{

public:
    int k;
    A(int val)
    {
        k = val;
        cout << "Default Constructor of A " << k<< endl;
    }
    A(int val,int va2):k(val){
        cout<<k<<endl;
    }
};
class B : public A
{
public:
    int a;
    B(int val) : A(val,val)
    {
        a = val;
        cout << "Default Constructor of B " << a << endl;
    }
    B(int val,int val2):A(val,val){
        cout<<"Constructor of B with two variables"<<endl;
    }
};
class C : private B
{
public:
    C(int val) : B(val,val)
    {
        cout << "Default Constructor of C" << endl;
    }
};

int main()
{
    C obj(5);

    return 0;
}
