#include <iostream>
using namespace std;
class SubjectMarks
{
protected:
    int English_marks;
    int Maths_marks;
    int Science_marks;
};
class Student : private SubjectMarks
{
private:
    int admissionNumber; // we are using other members of class SubjectMarks this is called aggregation
    string name;
    int totalMarks;
    int percentage;
    void calculateTotal();

public:
    Student();
    ~Student();
    void takeData()
    {
        cout << "Enter name of the student: " << endl;
        cin >> this->name;
        cout << "Enter admission number: " << endl;
        cin >> this->admissionNumber;
        cout << "Enter English marks: " << endl;
        cin >> this->English_marks;
        cout << "Enter maths marks: " << endl;
        cin >> this->Maths_marks;
        cout << "Enter Science marks: " << endl;
        cin >> this->Science_marks;
        totalMarks = English_marks + Maths_marks + Science_marks;
    }
    void showData()
    {
        cout << "Name is: " << name << " admission number is: " << admissionNumber << endl;
        this->calculateTotal();
    }
};

Student::Student()
{
    cout << "Default constructor" << endl;
}

Student::~Student()
{
    cout << "Destructor" << endl;
}

void Student::calculateTotal()
{
    float res = (float)totalMarks * 100 / 300;
    cout << "Total marks: " << totalMarks << " and percentage is : " << res << endl;
}

int main()
{
    Student s1;
    s1.takeData();
    s1.showData();
    return 0;
}