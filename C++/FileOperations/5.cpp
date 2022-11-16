#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ofstream f;
    ofstream myFile;
    myFile.open("example2.txt", ios::app);
    string input;
    getline(cin, input);
    myFile << input + "\n";
    myFile.close();
    string line;
    ifstream myFile1("example2.txt");

    if (myFile1.is_open())
    {
        myFile1.seekg(2, ios::end);
        while (getline(myFile1, line))
        {
            cout << line << endl;
        }
        myFile1.close();
    }
    else
    {
        cout << "File doesnot exist" << endl;
    }
    return 0;
}