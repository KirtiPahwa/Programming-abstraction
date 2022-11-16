#include <iostream>
using namespace std;
int k;
// k = 6; // we can't modify or initialise the variable value like this in global scope
int b = 5;
struct product
{
    int weight;
    double price;
} c, d; // here c and d are also objects of the product class
int main()
{
    product a, b; // a and b are objects or instances
    a.weight = 7;
    b.weight = 7;
    a.price = 7000;
    b.price = 8000;
    product e = {weight : 9, price : 8}; // new way to inititalise the object
    cout << e.weight << endl;
    k = 4; // can modify the global variable here

    return 0;
}