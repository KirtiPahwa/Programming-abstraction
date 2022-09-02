#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream myfile; // for writing into the file ofstream is used              // creating the object of filestream

    myfile.open("example.txt"); // will create the file if not exist and it will overwrite the file if exist already
    // myfile.open("example.txt",ios::ate);  //use this if you want to append the text into the file
    myfile << "Writing again to a file\n"; // this text will be inserted into the file
    myfile.close();

    // ios::ate will append the text in file not overwrite
    return 0;
}