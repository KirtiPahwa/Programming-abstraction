#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = true;
    if (n == 0 || n == 1)
    {
        cout << "NOT PRIME" << endl;
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            cout << "NOT PRIME" << endl;
            break;
        }
    }
    if (flag)
    {
        cout << "PRIME" << endl;
    }
    return 0;
}