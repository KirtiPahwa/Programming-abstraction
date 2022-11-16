#include <iostream>
using namespace std;
void numReverse(int n, int &ans)
{
    if (n == 0)
    {
        return;
    }
    ans = n % 10 + ans * 10;
    numReverse(n / 10, ans);
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    numReverse(n, ans);
    cout << ans << endl;
    return 0;
}