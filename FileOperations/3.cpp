#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    streampos begin, end;
    ofstream writing; // for writing
    ifstream reading; // for reading

    // or we can do
    fstream myFile("example.txt", ios::in | ios::out | ios::app); // dont need to make separate object of ofstream or ifstream we can give ios::in for ifstream and out for ofstream and app for append

    // tellg     // givnig pointer for writing
    //  seekg // for reading
    // seekg() is a function in the iostream library that allows us to seek an arbitrary position in a file. It is mainly used to set the position of the next character to be extracted from the input stream from a given file in C++ file handling.
    // seekg() is used to move the get pointer to a desired location with respect to a reference point.tellg() is used to know where the get pointer is in a file.seekp() is used to move the put pointer to a desired location with respect to a reference point.tellp() is used to know where the put pointer is in a file.
    // myFile.open();

    begin = myFile.tellg();
    myFile.seekg(0, ios::end);
    end = myFile.tellg();
    myFile.close();

    cout << "Size of the file is:" << end - begin << " bytes " << endl;

    return 0;
}