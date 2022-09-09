#include <iostream>
#include <string>
using namespace std;
#define MAX_NAME_LEN 60 // Maximum len of your name can't be more than 60

/*
1.preprocessor <string>: function is called by object
eg., v1.find(),v1.substring(),v1.at(),v1.compare();

2. preprocessor <cstring>: function is called normally
e.g., strcpy(s,d), strlen(char*), strcomp(char* a,char* b);

cstring is inherited from C and provides functions for working with C-style strings (arrays of char terminated by '\0' ). string was born in C++ and defines the std::string class along with its non-member functions


*/

int main()
{
    char *a = "Hello";  // here char is a primitive data type and a is a viraible // it ends with delimeter at the end that is '\0'
    string c = "Hello"; // string is a class here and b is a object // expect a fixed size
    string s1(4, 'a');  // string s1="aaaa"
    string v2("hello"); // copy constructor
    string v4 = v2;     // copy constructor

    string v3; // assignment operator overloading is here
    v3 = v2;

    // getlines and cin:
    // cin.getline(/*char*  or char array variable name  */, /*delimeter-can be size ,',','\n',  */); // to take the input of char array or pointer
    char y_name[MAX_NAME_LEN];
    cin.getline(y_name, MAX_NAME_LEN, '$'); //$ is a delimiter

    // getline(/* input stream or file stream e.g., cin  */, /* variable name */, /*delimeter*/);
    string str;
    getline(cin, str, ','); // 3rd parameter is a delimeter means read the input upto that specified delimeter;

    // Importand points:
    /* When user gives input:
    kirti
    pahwa

    A common problem while using getline with cin is getline does not ignore leading whitespace characters.

If getline is used after cin >>, the getline() sees this newline character as leading whitespace, and it just stops reading any further.

How to resolve it?

Call cin.ignore() before calling getline()

Or

make a dummy call getline() to consume the trailing newline character from the cin >>


    */

    cout << s1 << endl;
    string b = "Mny name is kirti";

    cout << b.insert(4, "sur") << endl;
    cout << b.find("i", 4) << endl;
    cout << a << endl;

    string b = "My name is kirti";

    cout << b.insert(3, "sur") << endl;
    auto found1 = b.find("i");
    auto found2 = b.find("i", found1 + 1);
    auto found3 = b.find("i", found2 + 1);
    auto found4 = b.find("i", found3 + 1); // no more 'i' is present there so it will return garbage value

    cout << found1 << " " << found2 << " " << found3 << " " << found4 << endl;
    cout << b << endl;

    return 0;
}