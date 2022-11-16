#include <iostream>
#include <set>
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
    set<int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            cout << arr[i] << endl;
            return 0;
        }
        mp.insert(arr[i]);
    }
    cout << "No duplicate exists" << endl;

    // xor method
    //  int ans=0;
    // for(int i=0;i<size;i++){
    //     ans= ans ^ arr[i] ;
    // }
    // for(int i=0;i<=size-2;i++){
    //     ans= ans ^ i;
    // }
    // return ans;
    return 0;
}