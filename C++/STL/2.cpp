#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int> v1(v);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    vector<int> v2(v1);
    v2.push_back(8);
    v2.push_back(9);

    // v.push_back(4); // this will not reflect on other vectors

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : v1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : v2)
    {
        cout << x << " ";
    }
    cout << endl;

    int count1 = 0;
    std::sort(v.begin(), v.end());   //  5 10 15 20 25
    std::sort(v1.begin(), v1.end()); // 10 20 30 40 50
    vector<int> ans(8);
    std::vector<int>::iterator it, end;
    end = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), ans.begin());
    for (it = ans.begin(); it != end; it++)
    {
        count1++;
    }
    cout << count1 << endl;

    map<int, int> mp;
    for (auto x : v)
    {
        mp[x]++;
    }
    for (auto x : v1)
    {
        mp[x]++;
    }
    for (auto x : v1)
    {
        mp[x]++;
    }
    int count = 0;
    for (auto x : mp)
    {
        if (x.second == 3)
        {
            count++;
            cout << x.first << " ";
        }
    }
    cout << endl;
    cout << count << endl;
    return 0;
}