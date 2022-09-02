#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* STL:-(Standard Template library)
1.Container(linear-array,deque,list,queue,stack  Associative:set,map,etc.)
2.Algorithms
3.Iterators(pointers)
*/

int main()
{

    vector<int> v;
    vector<int>::iterator it;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.insert(v.begin() + 2, 4, 100);

    // fill(v.begin() + 2, v.end(), 3);
    v.insert(v.end() - 2, 4, 200);
    // cout << v.size() << endl;     // no. of elements
    // cout << v.capacity() << endl; // memory location

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    // vector doubles the memory location once reach at the limit of size
    // So initially there was 1 element. So if we add 2nd element then capacity becomes 2*1 ie., 2 and size also 2.
    // So if we add 3th and then size=3 and capacity=4(2*2)
    // on adding 4th element size=4 and capacity=4
    // on adding then 5th element --->size=5 and capacity=8(4*2)
    // vector<int> v1;
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);
    // v1.push_back(1);

    // cout << v1.size() << endl;     // no. of elements
    // cout << v1.capacity() << endl; // memory location

    return 0;
}