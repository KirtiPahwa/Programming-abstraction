#include <iostream>
// #include "time.h"
#include <cstring>
using namespace std;
#define MAX_TRANSACTION_LEN 1000;
class Times
{
public:
    int date;
    int month;
    int year;
};

class Transaction : public Times
{
public:
    int accountNumber;
    int balance;
    char transactionType[1000]; // Cash cheque NetBanking
    void addTransaction(int accountNumber, int updatedBalance)
    {
        this->accountNumber = accountNumber;
        this->balance = updatedBalance;
        cout << "Enter today's date: " << endl;
        cin >> this->date;
        cout << "Enter current month: " << endl;
        cin >> this->month;
        cout << "Enter current year: " << endl;
        cin >> this->year;
        cout << "Enter the Transaction type(or mode of transaction):" << endl;
        cout << "Press 1 - For cash mode" << endl;
        cout << "Press 2 - For cheque mode" << endl;
        cout << "Press 3 - For NetBanking mode" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            strcpy(this->transactionType, "Cash");
        }
        else if (n == 2)
        {
            strcpy(this->transactionType, "Cheque");
        }
        else
        {
            strcpy(this->transactionType, "Net Banking");
        }
        cin.ignore();
    }
};