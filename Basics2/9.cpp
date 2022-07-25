#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        int k = i;
        for (int j = 1; j <= i; j++)
        {
            cout << k << " ";
            k++;
        }
        k -= 2;
        for (int j = 1; j < i; j++)
        {
            cout << k << " ";
            k--;
        }
        cout << endl;
    }
    return 0;
}