#include <iostream>
#include <fstream>
using namespace std;
class book
{
public:
    string bookId;
    book(int id = 0)
    {
        bookId = id;
    }
};

int main()
{
    book a(4);
    ofstream obj;
    obj.open("BooksData.txt", ios::app);

    obj.write((char *)&a, sizeof(a));

    string line;
    ifstream myfile("BooksData.txt"); // for reading the file . If example.txt exist then only
    if (myfile.is_open())
    {
        myfile.read((char *)&a, sizeof(a));
        myfile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    obj.close();

    return 0;
}