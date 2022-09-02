// Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring control to special functions called handlers.
// Types:Synchronised-(handled by computer eg., array size limit exceeded) , asynchronised- (eg. 2/0 is not handled so we have to do that.)
#include <iostream>
using namespace std;
int divide(int first, int second)
{
    try
    {
        if (second == 0)
        {
            // throw "string"; // this will not be handled by catch block of char // will raise exception //this is called throuw point
            // throw 'd'; // this will be handled by catch block of char
            throw(second);
            throw second; // this and uppper one is same
            cout << "Statement after the throw will not be execute. The program directly goes to catch block from the first throw pointer" << endl;
        }

        else
        {
            return first / second;
        }
    }
    catch (int x) // this integer name is optional ,you can also write simply catch(int)
    {
        cout << "Divide by zero" << endl;
        throw; // rethrow the exception and goes to the parent of the call
    }
}
// this is called stack
int main()
{
    int a, b, result;
    cin >> a >> b;
    try
    {
        result = divide(a, b);
        cout << result << endl;
    }
    catch (int)
    {
        cout << "Exception occured" << endl;
    }

    return 0;
}