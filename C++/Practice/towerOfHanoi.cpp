#include <iostream>
using namespace std;
void towerOfHanoi(char src, char dest, char helper, int n, int &count, int k)
{
    if (n > 0)
    {

        towerOfHanoi(src, helper, dest, n - 1, count, k);
        // cout << "Move a disc from " << src << " to " << dest << endl;
        towerOfHanoi(helper, dest, src, n - 1, count, k);
    }
    if (n == k && dest == 'B')
    {
        count++;
    }
}

int main()
{
    int n = 4;
    char src = 'A', dest = 'B', helper = 'C';
    int count = 0;
    int k = 1;
    towerOfHanoi(src, dest, helper, n, count, n - k + 1);
    cout << count << endl;

    return 0;
}