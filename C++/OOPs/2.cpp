#include <iostream>
using namespace std;

struct Student
{
    int rollNo;
    double cgpa;
    char gender; // class size will be = no. of variables * highest size of datatype present in the structure .Eg., here double is having highest size that is 8 so , total size of the object is 8*3 =24
    char k[2];

    // string a;
    // if string is there in struct the size will be 24 bytes + no .of variables * highest size of datatypes except string
    // if char[25] is there then it will also count the null character which is in last of the char array . So total length is 26
};

int main()
{
    int n;
    cout << "Enter the no of students " << endl;
    cin >> n;
    Student data[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the roll no for student " << i << endl;
        cin >> data[i].rollNo;
        cout << "Enter the cgpa for the student " << i << endl;
        cin >> data[i].cgpa;
        cout << "Enter the gender for the student " << i << endl;
        cin >> data[i].gender;
    }

    cout << "Size of object" << sizeof(data[0]) << endl;
    cout << &(data[0]) << endl; // address of data[0] and data[0].rollNo(1st variable) will be same and address of second element will be continuous to first element as like in array
    cout << &(data[0].rollNo) << endl;
    cout << &(data[0].cgpa) << endl;
    cout << &(data[0].gender) << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "The roll no of the student " << i << " is " << data[i].rollNo << endl;
        cout << "The roll no of the student " << i << " is " << data[i].cgpa << endl;
        cout << "The roll no of the student " << i << " is " << data[i].gender << endl;
    }

    return 0;
}