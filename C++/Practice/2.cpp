#include <iostream>
using namespace std;

int main()
{
    // do
    // {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    int sum = 0;
    int rowsum = 0;
    int a;
    int total = 0;
    bool flag = false;
    for (int i = 0; i < m * n; i++)
    {
        cin >> a;
        rowsum += a;
        if ((i + 1) % n == 0)
        {
            if (rowsum % 15 != 0)
            {
                cout << "Non valid input" << endl;
                flag = true;
                break;
            }
            rowsum = 0;
        }
        total += a;
    }
    if (!flag)
    {
        if (total < 300)
        {
            cout << "Non valid input" << endl;
        }
        else
        {
            cout << "Valid input" << endl;
        }
    }
    return 0;
}