#include <iostream>
using namespace std;
void output(int, float); // function prototype
void outputByReference(int *, float *);
void outputByReferenceUsingAmpercent(int &, float &);
int main()
{

    int rollNumber;
    float cgpa;
    char gender;
    cout << "Enter your roll number" << endl;
    cin >> rollNumber;
    cout << "Enter your cgpa" << endl;
    cin >> cgpa;
    cout << "Enter your gender" << endl;
    cin >> gender;
    output(rollNumber, cgpa);
    cout << " Ouput function call is over: " << rollNumber << " " << cgpa << endl;
    outputByReference(&rollNumber, &cgpa);
    cout << " OuputByReference function call is over: " << rollNumber << " " << cgpa << endl;
    outputByReferenceUsingAmpercent(rollNumber, cgpa);
    cout << " OuputByReference function call is over: " << rollNumber << " " << cgpa << endl;

    return 0;
}
// function to output the values
void output(int r, float c)
{
    cout << "Roll  no:" << r + 1 << endl;
    cout << "CGPA: " << c + 0.4 << endl;
}
void outputByReference(int *r, float *c)
{
    cout << "Inside outputByReference function with reference" << endl;
    *r += 1;
    *c += 0.5;
    cout << "Roll NO: " << (*r) << endl;
    cout << "Cgpa:  " << *c << endl;
}
void outputByReferenceUsingAmpercent(int &r, float &c)
{

    cout << "Inside outputByReferenceUsingAmpercent function" << r << endl;
    r += 1;
    c += 0.5;
    cout << "Roll NO: " << r << endl;
    cout << "Cgpa:  " << c << endl;
}