#include <iostream>
using namespace std;

int main()
{
    int size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 8, 4, 9, 10};
    int key;
    cin >> key;
    int index;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            index = i;
            count++;
            for (int i = index; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
        }
    }
    int k = size - 1;
    for (int i = 0; i < count; i++)
    {
        arr[k] = -1;
        k--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}