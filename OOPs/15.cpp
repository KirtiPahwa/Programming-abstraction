#include <iostream>
using namespace std;
const int size = 4;
int x[size] = {2, 3, 4};
class Vector
{
    int v[size];

public:
    Vector();
    Vector(int *x);
    friend Vector operator+(int, Vector);
    friend Vector operator+(Vector, int);
    friend istream &operator>>(istream &, Vector &);
    friend ostream &operator<<(ostream &, Vector &);
};
Vector::Vector()
{
    cout << "Default constructor" << endl;
    for (int i = 0; i < size; i++)
    {
        v[i] = 0;
    }
}
Vector operator+(int a, Vector b)
{
    Vector c;
    for (int i = 0; i < size; i++)
    {
        c.v[i] = a + b.v[i];
    }
    return c;
}
Vector operator+(Vector b, int a)
{
    Vector c;
    for (int i = 0; i < size; i++)
    {
        c.v[i] = a + b.v[i];
    }
    return c;
}

istream &operator>>(istream &din, Vector &b)
{
    for (int i = 0; i < size; i++)
    {
        din >> b.v[i];
    }
    return (din);
}
ostream &operator<<(ostream &dout, Vector &b)
{
    dout << "-->" << b.v[0] << " ";
    for (int i = 0; i < size; i++)
    {
        cout << b.v[i] << " ";
    }
    return (dout);
}

Vector::Vector(int *x)
{
    cout << "Copy constructor" << endl;
    for (int i = 0; i < size; i++)
    {
        v[i] = x[i];
    }
}

int main()
{
    Vector m;
    Vector n = x;
    cout << "Enter the element" << endl;
    cin >> m;
    cout << "\nm:" << m << "\n";
    Vector p, q;
    p = 2 + m;
    q = m + 2;
    cout << "\np:" << p << "\n";
    cout << "\np:" << q << "\n";

    return 0;
}