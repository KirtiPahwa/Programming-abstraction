#include <iostream>
#include <math.h>
using namespace std;
bool checkArmstrong(int n)
{
    int temp = n;
    int ans = 0;
    int no_of_digits = 0;
    while (temp)
    {
        no_of_digits++;
        temp /= 10;
    }
    temp = n;
    while (temp)
    {
        int l = ceil(pow(temp % 10, no_of_digits));
        ans += l;
        temp /= 10;
    }

    if (ans == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int decode(int n)
{
    int ans = 0;

    if (checkArmstrong(n))
    {
        int temp = n;
        int i = 0;
        while (temp)
        {
            i++;
            if (i % 2 == 0)
            {
                ans += temp % 10;
            }
            temp /= 10;
        }
        return ans;
    }
    else
    {
        int temp = n;
        int i = 0;
        while (temp)
        {
            i++;
            if (i % 2 != 0)
            {
                ans += temp % 10;
            }
            temp /= 10;
        }
        return ans;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << decode(n) << endl;
    return 0;
}

// 8208  8
// 54749  21
// 548834  16