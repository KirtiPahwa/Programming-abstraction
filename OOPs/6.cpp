#include <iostream>
using namespace std;

class Product
{
    int ingredients; // by default data members are private

public: // public members are accessible everywhere outside the class
    int weight;
    int getPrice()
    {
        return price;
    }
    void setPrice(int price)
    {
        if (price <= 1000)
            this->price = price;
        else
            cout << "Price should be less than 1000" << endl;
    }

private: // private member are not accessible outside the class not even in derived class
    float price;

protected: // protected members are just accessible in derived class
    int stock;

} a; // another object
int main()
{
    Product b; // object or instant of product class
    // b.ingredients=5; //cann't access this data memeber as this private member
    cout << "Enter the value of weight " << endl;
    cin >> b.weight;
    cout << "Enter the value of price" << endl;
    int price;
    cin >> price;
    b.setPrice(price);

    return 0;
}