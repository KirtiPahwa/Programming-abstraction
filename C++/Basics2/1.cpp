#include <iostream>
using namespace std;
void output(int n)
{
    if (n < 0)
    {
        return;
    }
    output(n - 1);
    cout << n << endl;
    return;
}
int main()
{
    output(5);
    return 0;
}