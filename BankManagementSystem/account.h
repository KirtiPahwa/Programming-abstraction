#include <iostream>
#include <fstream>
#include "time.h"
#include <cstring>
using namespace std;
class Account : public Time
{
public:
    long accountNumber;
    char accountType[100]; // savingAccount currentAccount fixedDepositAccount
    int balance;

    void addAccoutDetails()
    {
        cout << "Which type of account you want to register?" << endl;
        cout << "If you wanna open Saving account - press 1 : " << endl;
        cout << "If you wanna open Current account - press 2 : " << endl;
        cout << "If you wanna open Fixed Deposit account - press 3 : " << endl;
        int accountTypeInput;
        cin >> accountTypeInput;
        cin.ignore();
        if (accountTypeInput == 1)
        {
            strcpy(accountType, "Saving Account");
        }
        else if (accountTypeInput == 2)
        {
            strcpy(accountType, "Current Account");
        }
        else
        {
            strcpy(accountType, "Fixed Deposit Account");
        }
        cout << "Enter the Initial amount you want to deposit" << endl;
        cin >> balance;
        cout << "Enter today's date: " << endl;
        cin >> this->date;
        cout << "Enter current month: " << endl;
        cin >> this->month;
        cout << "Enter current year: " << endl;
        cin >> this->year;
        cin.ignore();
    }
};
// long Account::baseAccountNumber = 1011235780;