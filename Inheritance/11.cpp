#include <iostream>
using namespace std;
// ambiguity occurs when we use the variable which is creating ambiguity
class A
{
public:
    int a;
};
class B : virtual public A
{
};
class C : virtual public A
{
};
class D : public B, public C // if i inherit A and C then it will give us ambiguity error
{
};

int main()
{
    D obj1;
    cout << "Inside main function to print the val of A" << obj1.a << endl;    // a is ambiguous because a is coming from B and C both //this statement will run only when we use virtual keyword
    cout << "Inside main function to print the val of A" << obj1.B::a << endl; // a is not ambiguous because we have told obj1 to use a from B class using scope resoluter
    // or use virtual keyword which will tell that only one copy of a varible is inherited from either b or c into d (hybrid inheritance)

    return 0;
}