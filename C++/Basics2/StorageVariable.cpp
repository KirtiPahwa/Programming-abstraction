/* Variable storage:
In c++, an instance of a varialbe can be stored directly in memory , accessed by pointer,or accessed by reference.
Cube c;  =====   Cube&r=c;
Cube* ptr=&c;//ptr is pointing to c object

Direct Storage:
By default, variibale are stored directly in mremory
- The type of a variable has no modifier.
- The object takes up exactly its size in memory.
Eg., Cube c; //stores a cube in memory
     int i; //stores an integer in memory


Storage by pointer:
- The type of a variable is modified with an asterisk.
- A pointer takes a memory address width of memory(ex:64 bits on a 64-bit system.)
- The pointer points to the allocated space of the object.
Cube*c; //pointer to a cube in memory.
int*i;  //pointer to an integer in memory.


Storage by reference:
- A reference is an alias to existing memory and is denoted in the type with an ampersand(&).
- A reference does not store memory itself, it is only an alias to another variable.(It takes zero memory)
- The alias must be assigned when the variabel is initialized.
Cube& c=cube; //alias to the variable cube.
int& i=count;//alias to variable count.

*/

/*
Pass by_____
Identicall to storage, arguments can be passed to functions in three different ways:
Pass by value(default)
Pass by poiner(modified with *)
Pass by reference (modified with & ,acts as an alias)
*/

/*
Return By_____
Similarly, values can be reteurned all three ways as well:
-Return by value(default)
Return by pointer(modified with *)
Return by reference (modified with & , acts as an alias)
----Never return a reference to a stack variable created on the stack of your current function.--runtime error sometime. (But we can return reference to heap memory bcz heap memroy does not destroy on functions return. )
*/

#include <iostream>
using namespace std;
class Cube
{
public:
    int len;
    Cube()
    {
        len = 1;
        cout << "Default constructor invoked!!" << endl;
    }
    Cube(const Cube &obj)
    {
        len = obj.len;
        cout
            << "Copy constructor invoked!!" << endl;
    }
};

// Pass by_____
bool sendCube(Cube c) // c here will be another object and it will have another memory
{
    return true;
}
bool sendCube(Cube &c) // c here is just a alias and it will not have another memory
{
    return true;
}
bool sendCube(Cube *c) // c here is just a pointer to the actual object . so it will not create any extra memory.
{
    return true;
}

int main()
{
    Cube c;
    Cube d = c;  // copy constructor will be called //this is creting direct another memory for d object. Means there exist two cubes c and d.//construct another object.
    Cube &e = c; // this will just create alias for c // so no memroy created for e object.

    Cube *f = &c; // pointer to the cube// it will just create c object , will not create f object. It is just a pointer to object c.

    // ------Pass by _____
    Cube a;
    sendCube(a);
    sendCube(&a);
}
