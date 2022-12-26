/*
Heap memory allows us to create memory that is completely independent of a life cycle of a function, unlike stacked memory. Lets see how this works out.
Play video starting at ::16 and follow transcript0:16
In C++, if we ever need memory that is longer than the life cycle of a function, we have to use heap memory. The only way to create and keep memory in C++ is the use of the new keyword.
Play video starting at ::29 and follow transcript0:29
The new keyword is an operator in C++ that's going to return a pointer to the memory address starting of the new data, and not an instance of the data itself.

C++'s New operator will always do three things:
1. it's going to allocate memory on the heap for a data structure, whatever the data structure is that we're allocating. 2. It's going to initialize that data structure.
3. It's going to return a pointer to start off that data structure.

And the only time this memory's ever reclaimed/clear is when we use the delete.

Heap Memory:
int* numptr=new int;

-numptr is a simple variable which will store on the stack ( bcz int* numptr is not having any new keyword here (on left side of equal operator))
-Now, this new int will create heapp memory and this memory will sotre a integer. And that integer will be point by the numptr which is in stack memory.

It means stack memory will point to heap memory. Heap memory will be exist in entire length of the program unless we delete the memory.

*/
#include <iostream>
using namespace std;

int main()
{
    int *numPtr = new int;   // will create a variable numptr in stack memory and will create a memory for integer in heap memory.numptr in stack will point to heap memory's integer.
    cout << *numPtr << endl; // will give any random integer, as *numptr means integer at heap, and our heap memory is not storing any value.
    cout << numPtr << endl;  // will return the address of the integer numptr is pointing to and this address is of the heap memory which will be of lower lenght as compare to stack memory's address.
    cout << &numPtr << endl; // will return the address of the numptr vairable which is in stack memory. so address will be larger length than heap's .

    *numPtr = 42;
    cout << *numPtr << endl; // integer which is in heap memory will now have value 42.
    cout << numPtr << endl;
    cout << &numPtr << endl;

    delete numPtr; // it will just delete the heap memroy pointing by numptr . But the pointer numPtr will be still there in stack and its pointing to that memory only but memory does not contain any data there.This pionter is called now dangling pointer. So to handle this dangling pointer and to make code safe, i will point this numPtr to null pionter (in c++ ) after deleteing the memroy.

    numPtr = nullptr;
    // nullptr is a pointer that points to the memory address 0x0.
    /*
    nullptr represents a pointer to nowehere.
    address 0x0 is reserved and never used by the system.
    address 0x0 will always generate an "segmentation fault" when accessed.
    Calls to delete 0x0 are ignored.
    */

    /*Output:
    15863560
    0xf20fc8 (heap memory address)
    0x61ff0c (stack memrory addrss)  //heap address<stack address
    42
    0xf20fc8 (heap memory address)
    0x61ff0c (stack memrory addrss)
    */

    return 0;

    /* Heap memory structure :
    1. Unlike stack memory, it stores the memory as upward fashion. It will store the varaibel downward first(lower address--less length) and second vriable will be store on upward memory(higher address---more length.)

    Higher address.
        |
        |
    lower address.

    2. Address length of heap memory is less than stack memory's address length.
    */
}

// you will see in image that stack memory is allocated from upward to downward (larger address to lower address).
// And in heap memory, allocation is done from lower to  upward(lower address to larger address.)
