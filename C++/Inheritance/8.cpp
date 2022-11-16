#include <iostream>

using namespace std;

class batsman
{
public:
    int innings;
    int not_outs;
    int runs;
    string name;
    batsman()
    {
        // cout << "Default constructor" << endl;
    }
    float average()
    {
        float res = (float)runs / (innings - not_outs);
        return res;
    }
};

int main()
{
    batsman *arr;
    int n;
    cout << "Enter the no. of batsman you want to add" << endl;
    cin >> n;
    arr = new batsman[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name , innings, not_outs,runs:" << endl;
        cin >> arr[i].name >> arr[i].innings >> arr[i].not_outs >> arr[i].runs;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Average  of " << i << endl;
        cout << arr[i].average() << endl;
    }
    delete arr;

    return 0;
}