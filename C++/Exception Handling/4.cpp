/* Standard exceptions:-
exception	description
bad_alloc	thrown by new on allocation failure
bad_cast	thrown by dynamic_cast when it fails in a dynamic cast
bad_exception	thrown by certain dynamic exception specifiers
bad_typeid	thrown by typeid
bad_function_call	thrown by empty function objects
bad_weak_ptr	thrown by shared_ptr when passed a bad weak_ptr

array size limti exceeded and mont more(around 12)
*/

/*
what() funciton is virtual function which can be used with our defined  exception classes

*/
// bad_alloc standard exception
#include <iostream>
#include <exception>
using namespace std;
class myException : public exception
{
public:
    void what()
    {
        cout << "Trying to override the what funciton using the base class exception " << endl;
    }
};

int main()
{
    try
    {
        throw 8;
    }
    catch (exception &e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }
    catch (int)
    {
        cout << "Integer exception" << endl;
    }
    // catch (myException &Ex)
    // {
    //     Ex.what();
    // }
    return 0;
}
// HW:bad allocation,google photo