#include <iostream>
using namespace std;
int main()
{
    int amount;
    cin >> amount;
    amount += (amount * 8) / 100;
    cout << "Total amount after adding sales tax " << amount << endl;
    return 0;
}
