#include <iostream>
using namespace std;
int main()
{

    // In this program rollNumber is of int so input stream (input stream is a byte stream) , so it takes just int value of the provided input (i.e.,1568.4) and 0.4 is putted in buffer and then given to the float variable that is cgpa
    int rollNumber;
    char gender;
    float cgpa;
    cout << "Enter your roll number" << endl;
    cin >> rollNumber;
    cout << "Enter your cgpa" << endl;
    cin >> cgpa;
    cout << "Enter your gender" << endl;
    cin >> gender;
    cout << "Roll No is " << rollNumber << " , the gender is " << gender << " and cgpa is " << cgpa << endl;

    return 0;
}