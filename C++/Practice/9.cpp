#include <iostream>
using namespace std;

int main()
{
    float ip = 9, *p = &ip;
    cout << '\t' << *p << endl;
    float *a = &ip;

    return 0;
}