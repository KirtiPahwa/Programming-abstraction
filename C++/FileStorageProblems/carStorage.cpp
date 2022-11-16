#include <iostream>
#include <fstream>
using namespace std;
class CarVehicle
{
public:
    int carCode;
    int carPrice;
    int carQuantity;
    void addProductValues(int value)
    {
        this->carPrice = value;
    }
    void displayStockValues()
    {
        cout << "Stock value is : " << this->carQuantity << endl;
    }
};
void storeDataIntoTheFile(CarVehicle c[], int n)
{
    ofstream fout1;
    ofstream fout2;
    fout1.open("ObjectStorageOfCars.txt", ios::app);
    fout2.open("TextStorageOfCars.txt", ios::app | ios::binary);
    for (int i = 0; i < n; i++)
    {
        fout1.write((char *)&c[i], sizeof(c[i]));
        fout2 << c[i].carCode << " " << c[i].carPrice << " " << c[i].carQuantity << endl;
    }
    fout1.close();
    fout2.close();
}
void displayData()
{
    ifstream fin;
    fin.open("TextStorageOfCars.txt");
    int carCode, carPrice, carQuantity;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> carCode >> carPrice >> carQuantity;
            cout << "Car Code: " << carCode << "Car Price: " << carPrice << "Car Stock" << endl;
        }
    }
    else
    {
        cout << "File doesn't exist" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the no. of cars you want to add in the stock" << endl;
    cin >> n;
    CarVehicle cars[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the car code of the car " << i + 1 << endl;
        cin >> cars[i].carCode;
        cout << "Enter the car Price of the car " << i + 1 << endl;
        cin >> cars[i].carPrice;
        cout << "Enter the car Quantity of the car " << i + 1 << endl;
        cin >> cars[i].carQuantity;
    }
    storeDataIntoTheFile(cars, n);
    displayData();
    return 0;
}

/*
Let Cars list be a linear array of size N where each index of the array contains
following field Carcode, CArPrice and CarQuantity.
Declare a class CarVehicle with three data members and member functions to perform the following
a. Add values to the product list
b. Printing that total stock values

Also Save this data to file storage as text as well as object based

*/