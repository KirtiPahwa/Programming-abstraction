#include <iostream>
#include "person.h"
#include "account.h"
using namespace std;

#define MAX_OCCUPATION_LEN 100

class Customer : public Person, public Account
{

public:
    static long customers;
    char occupation[MAX_OCCUPATION_LEN];
    void addCustomerDetails();
};
void Customer::addCustomerDetails()
{
    customers++;
    this->addPersonalInformation();
    this->addAccoutDetails();
    cout << "Enter your occupation: " << endl;
    cin.getline(occupation, MAX_OCCUPATION_LEN);
}
long Customer::customers = 0;
