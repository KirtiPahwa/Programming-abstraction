#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    for (int i = 0; i < s.length() - 2; i++)
    {
        if (s[i] == 'R' && s[i + 1] == 'a' && s[i + 2] == 'm')
        {
            s[i] = 'S';
            s[i + 1] = 'a';
            s[i + 2] = 'm';
        }
    }
    cout << s << endl;
    return 0;
}