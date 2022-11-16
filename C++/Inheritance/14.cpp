#include <iostream>
using namespace std;
class Task
{
public:
    int no_of_tasks;
    int no_of_task_completed_on_time;
    float task_completion_rate;
};
class Performance : public Task
{
public:
    bool punctual;
};
class Employee : private Performance
{
    int number;
    char name[100];
    int experience;
    char totalGrades;
    float percentage;
    void calculateTotal()
    {
        task_completion_rate = ((float)no_of_task_completed_on_time + punctual) / no_of_tasks * 100;
        cout << task_completion_rate << endl;
        int totalMarks = 100 * no_of_task_completed_on_time;

        percentage = totalMarks / ((float)no_of_tasks * 100) * 100;
        if (percentage >= 90)
        {
            totalGrades = 'A';
        }
        else if (percentage >= 80)
        {
            totalGrades = 'B';
        }
        else if (percentage >= 70)
        {
            totalGrades = 'C';
        }
        else
        {
            totalGrades = 'D';
        }
    }

public:
    Employee()
    {
        cout << "Enter the data for the employees:" << endl;
        takeData();
    }
    void takeData()
    {
        cout << "Enter the number of the employee: " << endl;
        cin >> number;
        cout << "Enter the name of the employee: " << endl;
        cin.getline(name, 100);
        cout << "Enter the experience of the employee: " << endl;
        cin >> experience;
        cout << "Enter the no. of task given to the employee: " << endl;
        cin >> no_of_tasks;
        cout << "Enter the no. of task completed on time of the employee: " << endl;
        cin >> no_of_task_completed_on_time;
        cout << "Enter if the employee is punctual or not: 0:for no and 1:for yes" << endl;
        cin >> punctual;
        calculateTotal();
    }
    void showData()
    {
        cout << "Employee number: " << number << " , Name: " << name << " experience: " << experience << endl;
        cout << "Performance: " << endl;
        cout << "Punctuality: " << punctual << endl;
        cout << "Task Completion rate: " << task_completion_rate << endl;
        cout << "Total Grades: " << totalGrades << endl;
        cout << "Percentage: " << percentage << endl;
    }
    ~Employee()
    {
        showData();
    }
};

int main()
{
    int n;
    cout << "Enter the no. of employees" << endl;
    cin >> n;
    Employee employees[n];

    return 0;
}