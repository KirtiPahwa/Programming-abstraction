#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
T multiply(T a, T b)
{
    T ans = a * b;
    return ans;
}
int main()
{

    float a, b;
    cin >> a >> b;
    cout << fixed << setprecision(3) << endl;
    cout << multiply<float>(a, b) << endl;

    return 0;
}