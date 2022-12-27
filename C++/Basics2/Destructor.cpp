/*
Class Destructor:
When an instance of a class is cleaned up, the class destructor is the last call in a class's lifecycle.

Automatic Defalut Destructor:
there's an automatic default constructor that is provided for you for free, if you have no other destructor defined. The automatic default destructor only calls the destructor of other member variables and that's it.

An destructor should never be called directly. Instead, it is autmatically called when the object's memory is being reclaimed by the system:
-if the object is on the stack, when the function returns
-if the object is on  the heap, when delete is used

Custom Destructor:
To add custom behaviour to the end of life of the fuction , a custome destructor can be defined as:
- A custom destructor is a member function.
- The function's destructor is the name of the class preceded by a tilde ~ .
- All destructors have zero arguments and no return type.
Cube::~Cube(); //Custom destructor

Custome Destructor:
It is essential when an object allocates an exernal resource that must be closed or freed when the object is destroyed.
- heap memory
- open files
- shared memory
*/

#include <iostream>
using namespace std;

class Cube
{
public:
    Cube()
    {
        cout << "Constructor" << endl;
    }
    ~Cube()
    {
        cout << "Destructor" << endl;
    }
};
void cube_on_stack()
{
    Cube c; // object created in stack
    return; // at the time of returning , object c will also be destroyed.(means destructor will be called here)
}
void cube_on_heap()
{
    Cube *c1 = new Cube(); // object created in heap
    Cube *c2 = new Cube(); // object created in heap
    delete c1;             // only way to delete the object created in heap//means destructor will be called for c1 object.

    // but c2 is not being deleted here.
}
int main()
{
    cube_on_stack();
    cube_on_stack();

    return 0;
}
