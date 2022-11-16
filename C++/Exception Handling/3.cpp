#include <iostream>
using namespace std;

/*3 types:
throw b;
throw (b);
throw ; //rethrow the error
*/

// Stack Unbinding
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
    catch (int)
    {
        cout << "Divide by zero" << endl;
        throw; // rethrow the exception and goes to the parent of the call
    }
    return -1;
}
int display(int a, int b)
{
    try
    {
        return divide(a, b);
    }
    catch (int)
    {
        cout << "Divide exception handled" << endl;
        throw;
    }
}

int main()
{
    int a, b, result;
    cin >> a >> b;
    try
    {
        result = display(a, b);
        cout << result << endl;
    }
    catch (int)
    {
        cout << "Exception occured" << endl;
    }

    return 0;
}