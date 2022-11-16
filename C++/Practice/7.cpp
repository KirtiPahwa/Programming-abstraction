#include <iostream>
using namespace std;

int main()
{
    string a = "kirti";
    char b[] = "kirti";
    cout << sizeof(a) << endl;
    cout << sizeof(b) / sizeof(char) << endl;
    int i = 0;
    while (b[i] != '\0')
    {
        cout << b[i] << endl;
        i++;
    }

    return 0;
}