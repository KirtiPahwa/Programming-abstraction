#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    int arr2[m];
    for (int j = 0; j < m; j++)
    {
        cin >> arr2[j];
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
    set<int> r;
    for (int i = 0; i < n; i++)
    {
        r.insert(arr[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (r.find(arr2[i]) != r.end())
        {
            cout << arr2[i] << " ";
        }
    }
    cout << endl;

    return 0;
}