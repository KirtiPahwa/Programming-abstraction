#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "customer.h"
#include "transactions.h"
using namespace std;

void getBankDetails(int &totalCustomers, int &rateOfInterestPerAnnum, int &LatestAccountNumber)
{
    ifstream fin;
    fin.open("BankDetails.txt");
    int i = 1;
    string line;
    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            if (i == 1)
            {
                totalCustomers = stoi(line);
            }
            else if (i == 2)
            {
                rateOfInterestPerAnnum = stoi(line);
            }
            else if (i == 3)
            {
                LatestAccountNumber = stoi(line);
            }
            i++;
        }
        fin.close();
    }
    else
    {
        cout << "ERROR: BankDetails file is missing" << endl;
    }
}
void updateBankDetails(int totalCustomers, int rateOfInterestPerAnnum, int latestAccountNumber)
{
    int line;
    ofstream fout;
    fout.open("temp.txt");
    if (fout.is_open())
    {
        fout << totalCustomers << endl;
        fout << rateOfInterestPerAnnum << endl;
        fout << latestAccountNumber << endl;
        fout.close();
        remove("BankDetails.txt");
        rename("temp.txt", "BankDetails.txt");
    }
    else
    {
        cout << "ERROR:There might be some issue in creating the file" << endl;
    }
}
void displayAccountList()
{
    vector<Customer> customerList;
    ifstream fin;
    fin.open("Customers.txt", ios::binary);
    if (fin.is_open())
    {
        Customer c;
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            customerList.push_back(c);
        }
        fin.close();
        cout << "Details of Account Holders: " << endl;
        for (int i = 0; i < customerList.size() - 1; i++)
        {
            cout << "Customer " << i + 1 << " :" << endl;
            cout << "Account Number: " << customerList[i].accountNumber << endl;
            cout << "Balance: " << customerList[i].balance << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some customer into the file using addCustomer() function " << endl;
    }
}
void calculateInterest()
{
    cout << "Enter the account number of the account whose Interest you want to calculate: " << endl;
    int tempAccountNumber;
    cin >> tempAccountNumber;
    vector<Customer> customerList;
    ifstream fin;
    fin.open("Customers.txt", ios::binary);
    if (fin.is_open())
    {
        Customer c;
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            customerList.push_back(c);
        }
        fin.close();
        for (int i = 0; i < customerList.size() - 1; i++)
        {
            if (customerList[i].accountNumber == tempAccountNumber)
            {
                time_t t = time(0);
                tm *now = localtime(&t);
                int date = now->tm_mday;
                int month = now->tm_mon + 1;
                int year = now->tm_year + 1900;
                bool withdrawnAfterMonth;
                int days;
                if (customerList[i].month - month > 1)
                {
                    days = (30 - customerList[i].date) + (date) + (customerList[i].month - month - 1) * 30;
                    withdrawnAfterMonth = true;
                }
                else if (customerList[i].month - month == 1)
                {
                    days = (30 - customerList[i].date) + (date);
                    if (days >= 30)
                    {
                        withdrawnAfterMonth = true;
                    }
                    else
                    {
                        withdrawnAfterMonth = false;
                    }
                }
                else
                {
                    days = date - customerList[i].date;
                    if (days >= 30)
                    {
                        withdrawnAfterMonth = true;
                    }
                    else
                    {
                        withdrawnAfterMonth = false;
                    }
                }
                if (withdrawnAfterMonth == true)
                {
                    int totalCustomers;
                    int rateOfInterestPerAnnum;
                    int latestAccountNumber;
                    getBankDetails(totalCustomers, rateOfInterestPerAnnum, latestAccountNumber);
                    int interest = (rateOfInterestPerAnnum * customerList[i].balance * ((days) / (12 * 30)));
                    cout << "Calculated Interest is " << interest << endl;
                    break;
                }
                else
                {
                    cout << "Interest cannot be retrieved as customer has withdrawn money in the last month" << endl;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some customer into the file using addCustomer() function " << endl;
    }

    cin.ignore();
}
void addCustomer()
{
    ofstream fout;
    fout.open("Customers.txt", ios::binary | ios::app);
    Customer customer;
    customer.addCustomerDetails();
    int totalCustomers;
    int rateOfInterestPerAnnum;
    int latestAccountNumber;
    getBankDetails(totalCustomers, rateOfInterestPerAnnum, latestAccountNumber);
    totalCustomers++;
    latestAccountNumber++;
    customer.customers = totalCustomers;
    customer.accountNumber = latestAccountNumber;
    updateBankDetails(totalCustomers, rateOfInterestPerAnnum, latestAccountNumber);
    fout.write((char *)&customer, sizeof(customer));
    fout.close();
}
void checkAccount()
{
    cout << "Enter the account number of the account which you want to check: " << endl;
    int checkAccountNumber;
    cin >> checkAccountNumber;
    cin.ignore();
    vector<Customer> customerList;
    ifstream fin;
    fin.open("Customers.txt", ios::binary);
    if (fin.is_open())
    {
        Customer c;
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            customerList.push_back(c);
        }
        fin.close();
        for (int i = 0; i < customerList.size() - 1; i++)
        {
            if (customerList[i].accountNumber == checkAccountNumber)
            {
                cout << "Account with the given details Found!!" << endl;
                return;
            }
        }
        cout << "Account Not Found!!" << endl;
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some customer into the file using addCustomer() function " << endl;
    }
}
void deleteAccountHolderDetails()
{
    cout << "Enter the account number of the account which you want to delete " << endl;
    int deleteAccountNumber;
    cin >> deleteAccountNumber;
    cin.ignore();
    Customer c;
    ofstream fout;
    ifstream fin;
    fin.open("Customers.txt", ios::binary | ios::in);
    if (!fin.is_open())
    {
        cout << "ERROR:Customer file doesnot exist . So first perform addCustomer()" << endl;
        return;
    }
    fout.open("temp.txt", ios::binary | ios::out);
    while (!fin.eof())
    {
        fin.read((char *)&c, sizeof(c));
        if (c.accountNumber != deleteAccountNumber)
        {
            fout.write((char *)&c, sizeof(c));
        }
    }
    fin.close();
    fout.close();
    try
    {
        remove("Customers.txt");
        rename("temp.txt", "Customers.txt");
    }
    catch (...)
    {
        cout << "ERROR:The issue is generating during deleting the file. Check first if the Customers.txt file exist" << endl;
        return;
    }
    int totalCustomers;
    int rateOfInterestPerAnnum;
    int latestAccountNumber;
    getBankDetails(totalCustomers, rateOfInterestPerAnnum, latestAccountNumber);
    totalCustomers--;
    updateBankDetails(totalCustomers, rateOfInterestPerAnnum, latestAccountNumber);
    cout << "Account Deleted Successfully" << endl;
}
void updateAccountHolderName()
{
    cout << "Enter the account number of the account whose Account Name you want to retrieve/update: " << endl;
    int updateAccountNumber;
    cin >> updateAccountNumber;
    cin.ignore();
    Customer c;
    ofstream fout;
    ifstream fin;
    fin.open("Customers.txt", ios::binary | ios::in);
    if (!fin.is_open())
    {
        cout << "ERROR:Customer file doesnot exist . So first perform addCustomer()" << endl;
        return;
    }
    fout.open("temp.txt", ios::binary | ios::out);
    while (!fin.eof())
    {
        fin.read((char *)&c, sizeof(c));
        if (c.accountNumber == updateAccountNumber)
        {
            cout << "Account Found with the  name: " << c.firstName << " " << c.lastName << endl;
            cout << "Enter the first name you want to update with:" << endl;
            cin >> c.firstName;
            cout << "Enter the last name you want to update with:" << endl;
            cin >> c.lastName;
            cout << c.firstName << " " << c.lastName << endl;
            cin.ignore();
            fout.write((char *)&c, sizeof(c));
            return;
        }
        fout.write((char *)&c, sizeof(c));
    }
    fin.close();
    fout.close();
    try
    {
        remove("Customers.txt");
        rename("temp.txt", "Customers.txt");
    }
    catch (...)
    {
        cout << "ERROR:The issue is generating during deleting the file. Check first if the Customers.txt file exist" << endl;
        return;
    }
    cout << "Account Holder Name Updated Successfully!!" << endl;
}
void retrieveBalance()
{
    cout << "Enter the account number of the account whose balance you want to retrieve: " << endl;
    int checkAccountNumber;
    cin >> checkAccountNumber;
    cin.ignore();
    vector<Customer> customerList;
    ifstream fin;
    fin.open("Customers.txt", ios::binary);
    if (fin.is_open())
    {
        Customer c;
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            customerList.push_back(c);
        }
        fin.close();
        for (int i = 0; i < customerList.size() - 1; i++)
        {
            if (customerList[i].accountNumber == checkAccountNumber)
            {
                cout << "Balance of the entered account number is: " << customerList[i].balance << endl;
                return;
            }
        }
        cout << "Account Not Found!!" << endl;
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some customer into the file using addCustomer() function " << endl;
    }
}
void updateAccountHolderAddress()
{
    cout << "Enter the account number of the account whose Address you want to retrieve/update: " << endl;
    int updateAccountNumber;
    cin >> updateAccountNumber;
    cin.ignore();
    Customer c;
    ofstream fout;
    ifstream fin;
    fin.open("Customers.txt", ios::binary | ios::in);
    fout.open("temp.txt", ios::binary | ios::out);

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            if (c.accountNumber == updateAccountNumber)
            {
                cout << "Account Found with the address:" << c.address << endl;
                cout << "Enter the address you want to update with:" << endl;
                cin.getline(c.address, MAX_ADDRESS_LEN);
                fout.write((char *)&c, sizeof(c));
                return;
            }
            fout.write((char *)&c, sizeof(c));
        }
        fin.close();
        fout.close();
        try
        {
            remove("Customers.txt");
            rename("temp.txt", "Customers.txt");
        }
        catch (...)
        {
            cout << "ERROR:The issue is generating during deleting the file. Check first if the Customers.txt file exist" << endl;
            return;
        }
        cout << "Account Address Updated Successfully!!" << endl;
    }
    else
    {
        cout << "ERROR:Customer file doesnot exist . So first perform addCustomer()" << endl;
    }
}
void displayLastEntry()
{
    vector<Transaction> transactionList;
    ifstream fin;
    fin.open("Transaction.txt", ios::binary);
    if (fin.is_open())
    {
        Transaction c;
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            transactionList.push_back(c);
        }
        fin.close();
        cout << "Account Number of the last entry: " << endl;
        cout << transactionList[transactionList.size() - 1].accountNumber << endl;
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some customer into the file using addCustomer() function " << endl;
    }
}
void displayInformation()
{
    cout << "Enter the account number whose information you want to display: " << endl;
    int checkAccountNumber;
    cin >> checkAccountNumber;
    cin.ignore();
    vector<Customer> customerList;
    ifstream fin;
    fin.open("Customers.txt", ios::binary);
    if (fin.is_open())
    {
        Customer c;
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            customerList.push_back(c);
        }
        fin.close();
        for (int i = 0; i < customerList.size() - 1; i++)
        {
            if (customerList[i].accountNumber == checkAccountNumber)
            {
                cout << endl;
                cout << "Details of the entered account number are:" << endl;
                cout << endl;
                cout << "Personal Information:" << endl;
                cout << "Name: " << customerList[i].firstName << " " << customerList[i].lastName << endl;
                cout << "Phone Number: " << customerList[i].phoneNumber << endl;
                cout << "Date Of Birth: " << customerList[i].dateOfBirth << endl;
                cout << "Address: " << customerList[i].address << endl;
                cout << "Email Id: " << customerList[i].email << endl;
                cout << "Aadhar Card Number: " << customerList[i].aadharCardNumber << endl;
                cout << "Pan Card Number: " << customerList[i].panCardNumber << endl;
                cout << "Occupation: " << customerList[i].occupation << endl;
                cout << endl;
                cout << "Account Details:" << endl;
                cout << "Account Number: " << customerList[i].accountNumber << endl;
                cout << "Account Type: " << customerList[i].accountType << endl;
                cout << "Current Balance: " << customerList[i].balance << endl;
                return;
            }
        }
        cout << "Account Not Found!!" << endl;
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some customer into the file using addCustomer() function " << endl;
    }
}
void addTransactionRecord(int accountNumber, int updatedBalance)
{
    ofstream fout;
    fout.open("Transaction.txt", ios::app | ios::binary);
    Transaction t;
    t.addTransaction(accountNumber, updatedBalance);
    fout.write((char *)&t, sizeof(t));
    fout.close();
}
void withdraw()
{
    cout << "Enter the account number from which you want to withdraw" << endl;
    int tempAccountNumber;
    cin >> tempAccountNumber;
    cin.ignore();
    Customer c;
    ofstream fout;
    ifstream fin;
    fin.open("Customers.txt", ios::binary | ios::in);
    fout.open("temp.txt", ios::binary | ios::out);
    int updatedBalance;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            if (c.accountNumber == tempAccountNumber)
            {
                cout << "Account Found with the entered account Number" << endl;
                cout << "Enter the amount you want to withdraw :" << endl;
                int withdrawMoney;
                cin >> withdrawMoney;
                cin.ignore();
                c.balance -= withdrawMoney;
                updatedBalance = c.balance;
                time_t t = time(0);
                tm *now = localtime(&t);
                c.date = now->tm_mday;
                c.month = now->tm_mon + 1;
                c.year = now->tm_year + 1900;
                fout.write((char *)&c, sizeof(c));
                break;
            }
            fout.write((char *)&c, sizeof(c));
        }
        fin.close();
        fout.close();
        try
        {
            remove("Customers.txt");
            rename("temp.txt", "Customers.txt");
        }
        catch (...)
        {
            cout << "ERROR:The issue is generating during deleting the file. Check first if the Customers.txt file exist" << endl;
            return;
        }
        addTransactionRecord(tempAccountNumber, updatedBalance);
        cout << "Account Details Updated Successfully!!" << endl;
    }
    else
    {
        cout << "ERROR:Customer file doesnot exist . So first perform addCustomer()" << endl;
    }
}
void deposit()
{
    cout << "Enter the account number in which you want to deposit" << endl;
    int tempAccountNumber;
    cin >> tempAccountNumber;
    cin.ignore();
    Customer c;
    ofstream fout;
    ifstream fin;
    fin.open("Customers.txt", ios::binary | ios::in);
    fout.open("temp.txt", ios::binary | ios::out);
    int updatedBalance;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            if (c.accountNumber == tempAccountNumber)
            {
                cout << "Account Found with the entered account Number" << endl;
                cout << "Enter the amount you want to deposit :" << endl;
                int withdrawMoney;
                cin >> withdrawMoney;
                cin.ignore();
                c.balance += withdrawMoney;
                updatedBalance = c.balance;
            }
            fout.write((char *)&c, sizeof(c));
        }
        fin.close();
        fout.close();
        try
        {
            remove("Customers.txt");
            rename("temp.txt", "Customers.txt");
        }
        catch (...)
        {
            cout << "ERROR:The issue is generating during deleting the file. Check first if the Customers.txt file exist" << endl;
            return;
        }
        addTransactionRecord(tempAccountNumber, updatedBalance);
        cout << "Account Details Updated Successfully!!" << endl;
    }
    else
    {
        cout << "ERROR:Customer file doesnot exist . So first perform addCustomer()" << endl;
    }
}
void depositAndWithdraw()
{
    cout << "If you want to withdraw the money then press- 1 else 0" << endl;
    bool withOrDep;
    cin >> withOrDep;
    cin.ignore();
    if (withOrDep == 1)
    {
        withdraw();
    }
    else if (withOrDep == 0)
    {
        deposit();
    }
}
void record()
{
    cout << "Enter the account number of which you want to see transaction details" << endl;
    int temp;
    cin >> temp;
    cin.ignore();
    vector<Transaction> t;
    ifstream fin;
    fin.open("Transaction.txt", ios::binary);
    if (fin.is_open())
    {
        Transaction c;
        while (!fin.eof())
        {
            fin.read((char *)&c, sizeof(c));
            t.push_back(c);
        }
        fin.close();
        cout << "Transaction Details: " << endl;
        for (int i = 0; i < t.size() - 1; i++)
        {
            if (t[i].accountNumber == temp)
            {
                cout << "Account Number: " << t[i].accountNumber << endl;
                cout << "Transaction mode: " << t[i].transactionType << endl;
                cout << "Balance: " << t[i].balance << endl;
                cout << "Date: " << t[i].date << endl;
                cout << "Month: " << t[i].month << endl;
                cout << "Year: " << t[i].year << endl;
            }
        }
    }
    else
    {
        cout << "ERROR: File does not exist. So first add some customer into the file using addCustomer() function " << endl;
    }
}

int main()
{
    int operations;
    bool iterate;

    do
    {
        cout << "You can perform the following functions:" << endl;
        cout << "Press 1 - For adding a new customers" << endl;
        cout << "Press 2 - To display details of account of all the account holders " << endl;
        cout << "Press 3 - To delete the information related to the account holder from the customer data file " << endl;
        cout << "Press 4 - To update the balance after customer has performed a deposit or withdraw transaction " << endl;
        cout << "Press 5 - To display the account number of the last entry" << endl;
        cout << "Press 6 - To check from the customer data file whether an account exist or not " << endl;
        cout << "Press 7 - To retrieve/update the name of the account holder " << endl;
        cout << "Press 8 - To retrieve/update the address of the account holder " << endl;
        cout << "Press 9 - To retrieve the balance of the account holder " << endl;
        cout << "Press 10 - To returns the record number from the customer file when an employee of the bank enters the account number related to an account holder(Transaction details along with the account information)" << endl;
        cout << "Press 11 - To display all the information related to an account holder from  the cutomer file on the basis of specified account number " << endl;
        cout << "Press 12 - To calculate the interest to date on the deposit (if the customer has not withdrawn for more than a month)" << endl;
        cin >> operations;
        cin.ignore();
        switch (operations)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            displayAccountList();
            break;
        case 3:
            deleteAccountHolderDetails();
            break;
        case 4:
            depositAndWithdraw();
            break;
        case 5:
            displayLastEntry();
            break;
        case 6:
            checkAccount();
            break;
        case 7:
            updateAccountHolderName();
            break;
        case 8:
            updateAccountHolderAddress();
            break;
        case 9:
            retrieveBalance();
            break;
        case 10:
            record();
            break;
        case 11:
            displayInformation();
            break;
        case 12:
            calculateInterest();
            break;
        default:
            break;
        }
        cout << "To perform more functions , press 1 else 0" << endl;
        cin >> iterate;
        if (iterate != 1)
        {
            exit(1);
        }

    } while (iterate == 1);

    return 0;
}

// have to add ifsc,fixed deposit of banks
// have to correct customer no.
// have to check that why its printing 1 more than total no. of customers
// change the name of customer file