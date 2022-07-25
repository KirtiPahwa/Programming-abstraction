#include <iostream>
using namespace std;

int main()
{
    int input = 0;
    cout << "How many elements do you want to add?";
    cin >> input;
    const int val = input;
    double foo[val];

    for (int i = 0; i < input; i++)
    {
        cout << "Enter the element you want to insert " << endl;
        cin >> foo[i];
    }
    // operations to be handled by this code
    enum arrayoperations
    {
        traverse = 1,
        insert,
        search,
        deleteElement
    };
    int k = input - 1;

    do
    {
        int options = 0;
        cout << "Choose any of the following operations:";
        cout << "1. Traverse Array";
        cout << "2. Insert at a location";
        cout << "3. Search element in array";
        cout << "4. Delete Element from array";
        cin >> options;
        int key;
        int count;

        switch (options)
        {
        case traverse:
            for (int i = 0; i < input; i++)
            {
                cout << foo[i] << " ";
            }
            cout << endl;
            break;
        case insert:
            int ele, ind;
            cout << "Enter the element you want to inserted" << endl;
            cin >> ele;
            cout << "Enter the location you want to insert at" << endl;
            cin >> ind;
            for (int i = input - 1; i > ind; i--)
            {
                foo[i] = foo[i - 1];
            }
            foo[ind] = ele;
            break;
        case search:
            int n;
            cout << "Enter the element you want to search" << endl;
            cin >> n;
            for (int i = 0; i < input; i++)
            {
                if (foo[i] == n)
                {
                    cout << "The location of the element is : " << i << endl;
                }
            }
            break;
        case deleteElement:
            cout << "Enter the element you want to delete " << endl;
            cin >> key;
            int index;
            count = 0;
            for (int i = 0; i < input; i++)
            {
                if (foo[i] == key)
                {
                    index = i;
                    count++;
                    for (int i = index; i < input - 1; i++)
                    {
                        foo[i] = foo[i + 1];
                    }
                }
            }
            int k;
            k = input - 1;
            for (int i = 0; i < count; i++)
            {
                foo[k] = -1;
                k--;
            }

            // Better approach:
            for (int i = 0; i < input; i++)
            {
                if (foo[i] == key)
                {
                    foo[i] = -1;
                }
            }
            for (int i = 0; i < input; i++)
            {
                if (foo[i] == -1)
                {
                }
            }

            break;
        default:
            cout << "Invalid operation";
        }
        int n;
        cout << "Enter 1 :If you want to continue " << endl;
        cout << "Enter 0 :If you want to exit " << endl;
        cin >> n;
        if (n == 0)
        {
            break;
        }

        /// add logic to exit or continue the loop
    } while (1);

    // // logic for input
    // for (int counter = 0; counter < val; counter++)
    // {
    //     cout << "Enter the value for index " << counter << " : ";
    //     cin >> foo[counter];
    // }
    // // logic for print/traverse and array
    // for (int counter = 0; counter < val; counter++)
    // {
    //     cout << "value for index " << foo[counter] << endl;
    // }
    // cout << "Enter the value to be deleted:";

    return 0;
}
