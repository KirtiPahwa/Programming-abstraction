#include <iostream>
using namespace std;

int main()
{
    int a[5][5] = {};
    // int a[2][2] = {{9, 8}, {8, 7}};
    // int *a[2] = {{9, 8}, {8, 7}};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int b[1][1][1] = {{{2}}};
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < 1; k++)
            {
                cout << b[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}