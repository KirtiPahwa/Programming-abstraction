#include <iostream>
using namespace std;
int func(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int sum = n % 10 + func(n / 10);
    return sum;
}

int main()
{

    cout << func(9021) << endl;
    return 0;
}