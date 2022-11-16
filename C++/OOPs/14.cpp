#include <iostream>
using namespace std;
class complex
{
private:
   float real;
   float img;

public:
   complex(float a = 0, float b = 0)
   {
      this->real = a;
      this->img = b;
   }
   friend complex operator+(complex, complex); // we have to pass 2 parameters for binary unlike simple operator overloading
   friend complex operator+(complex, complex);
   friend complex operator+(complex, float);
   friend complex operator+(float, complex);
   void display()
   {
      cout << this->real << " + i" << this->img << endl;
   }
};
complex operator+(complex a, complex b)
{
   complex res;
   res.real = a.real + b.real;
   res.img = a.img + b.img;
   return res;
}
complex operator+(complex a, float b)
{
   complex res;
   res.real = a.real + b;
   res.img = a.img + b;
   return res;
}
complex operator+(float a, complex b)
{
   complex res;
   res.real = a + b.real;
   res.img = a + b.img;
   return res;
}
// friend function :
// two parameters for binary operators and one for unary

int main()
{
   complex a(2, 3), b(4, 5);
   complex c = a + b;
   complex d = a + 3;
   complex e = 3 + b;
   c.display();
   return 0;
}

// Friend function that cann't  be overload
// = (assignment),() (function call) ,[] (subscripting operator),->(class member)