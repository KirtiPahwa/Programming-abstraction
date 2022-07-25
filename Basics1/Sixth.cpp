#include <iostream>
using namespace std;
inline int func(int s)
{
    return s * s * s;
}
int main()
{
    // inline functions :just use the keyword before the function as like inline int func(){}
    cout << func(4) << endl;
    return 0;
}

/* Inline functions:
Compiler ignore the inline request:
1.If a functions contains a loop.
2. If a function is recusive.
3.If a function contain static variables.
4. If a function return type is other than void, and the return statement doesnot exist in function body.
5. If a function contains switch or go to statement.


Advantages:
1. Function call overhead doesnot occur
        -- the overhead of push/pop variables on the stack when function is called.
        -- overhead of a return call from a function.
        (overhead is cost, time or memory usage)
2. this function is useful for embedded systems bcz inline can yield less code than the function call preamble and return.


*/
