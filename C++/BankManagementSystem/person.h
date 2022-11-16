#include <iostream>
using namespace std;
#define MAX_NAME_LEN 200
#define MAX_DATE_OF_BIRTH_LEN 100
#define MAX_ADDRESS_LEN 1000
#define MAX_EMAIL_LEN 100

class Person
{
public:
    char firstName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    long long phoneNumber;
    char dateOfBirth[MAX_DATE_OF_BIRTH_LEN];
    char address[MAX_ADDRESS_LEN];
    char email[MAX_EMAIL_LEN];
    long long panCardNumber;
    long long aadharCardNumber;

    void addPersonalInformation()
    {
        cout << "Enter your firstName: " << endl;
        cin.getline(firstName, MAX_NAME_LEN);
        cout << "Enter your lastName:" << endl;
        cin.getline(lastName, MAX_NAME_LEN);
        cout << "Enter your mobileNumber:" << endl;
        cin >> phoneNumber;
        cout << "Enter your Date of Birth in given format - {DD/MM/YYYY} : " << endl;
        cin.ignore();
        cin.getline(dateOfBirth, MAX_DATE_OF_BIRTH_LEN);
        cout << "Enter your Email Id:" << endl;
        cin.getline(email, MAX_EMAIL_LEN);
        cout << "Enter your address ( same Address which is mentioned in your aadhar card):" << endl;
        cin.getline(address, MAX_ADDRESS_LEN);
        cout << "Enter your Pan Card Number" << endl;
        cin >> panCardNumber;
        cin.ignore();
        cout << "Enter your Aadhar Card Number" << endl;
        cin >> aadharCardNumber;
        cin.ignore();
    }
};
