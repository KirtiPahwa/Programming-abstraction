// header file defines the interface to the class but it does not include the implementation of those functions . but it does not include the implementation of those functions. So, what we expect in a header file is going to be something akin to an API, where we're going to define exactly what programmers can call in our class and exactly where a class stores, but not how those things work. 
#pragma once // this instructs the compiler to only compile the code once.Even if multiple people use our class, we'll only want the definition of our class to be defined exactly once. 
#include <iostream>
// In the CPP file, we call this file the implementation file and it's the code that contains all of the logic to implement our class. Let's take a look at this
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
