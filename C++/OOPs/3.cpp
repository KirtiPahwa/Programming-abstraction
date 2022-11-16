#include <iostream>
using namespace std;
struct gst
{
    int sales;
};

struct product
{
    int weight;
    int price;
    int *gst;
};

int main()
{
    product a = {weight : 8, price : 3000};
    product *b = &a;
    product *c;
    cout << b->weight << endl; // this is equivalent to (*b).weight
    cout << (*b).weight << endl;
    *a.gst = 3; // wrong
    cout << *(a.gst) << endl;
    // a.*gst.sales;
    // * (a.b) is equivalent to *a.b

    return 0;
}