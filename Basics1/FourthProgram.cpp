#include <iostream>
using namespace std;
int main()
{
    int amount;
    cin >> amount;
    amount += (amount * 8) / 100;
    cout << "Total amount after adding sales tax " << amount << endl;
    int b, a;
    a = (b = 4, b + 5);
    cout << a << endl;

    int c = 1, d = 4;
    c += d -= 6;
    cout << c << " " << d << endl;
    return 0;
}
