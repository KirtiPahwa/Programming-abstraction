#include <iostream>
using namespace std;
int main()
{
    float temp_fahrenheit;
    cout << "Enter temperatur in Fahrenheit " << endl;
    cin >> temp_fahrenheit;
    float temp_celsius = (temp_fahrenheit - 32) * 5 / 9;
    cout << "Temperature in Celsius is " << temp_celsius << endl;

    return 0;
}
