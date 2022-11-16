#include <iostream>
using namespace std;
int binaryAddition(int m, int n)
{
    int ans = 0;
    int carry = 0;
    int sum[20];
    int r = 0;
    while (m || n || carry)
    {
        sum[r++] = (m % 10 + n % 10 + r) % 2;
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    binaryAddition(m, n);
    return 0;
}