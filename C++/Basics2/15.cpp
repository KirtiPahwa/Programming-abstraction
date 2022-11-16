#include <iostream>
using namespace std;

int main()
{
    char **strPtr;
    char c = '3';
    char *str = &c;
    strPtr = &str;
    free(strPtr); // Here str becomes a dangling pointer now
    cout << str << endl;
    cout << *str << endl;
    cout << **strPtr << endl; // here strPtr is a dangling pointer //to avoid this use str=nullptr
    return 0;
}