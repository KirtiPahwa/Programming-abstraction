#include <iostream>
using namespace std;

int main()
{
    string c;
    int n;
    cin >> n;
    cin.ignore(); // its important to use cin.ignore before using getline() else getline will take enter value left by cin and will not store string in it
    int a;
    cin >> a;
    cin.ignore();
    getline(cin, c);
    cout << a << endl;
    cout << n << endl;
    cout << c << endl;

    return 0;
}