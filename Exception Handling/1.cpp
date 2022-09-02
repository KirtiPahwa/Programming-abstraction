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
            string a = "d";
            throw a; // this will not be handled by catch block of char // will raise exception //this is called throuw point
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
    // if error is not handled by catch block then error is :terminate called after throwing an instance of int
    catch (string x)
    {
        cout << "Divide by zero(string)" << endl;
        // also gives 1 indicates the unsuccessfull termination of the function (by default)
    }
    catch (char x)
    {
        cout << "Divide by zero(char)" << endl;
        // also gives 1 indicates the successfull termination of the program
    }
    catch (int x)
    {
        cout << "Divide by zero(int)" << endl;
    }
    catch (...)
    {
        cout << "Unhandled exception" << endl; // we cann't put the default catch block above (compile time error)
    }
    // return 2; // if i put this statement then by default value of the termination of the function will not show . If function doesnot return anything then by default funciton will return 1;
}
int main()
{
    int a, b, result;
    cin >> a >> b;
    cout << divide(a, b);

    return 0;
}