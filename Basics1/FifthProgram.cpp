#include <iostream>
#include <iomanip>
using namespace std;
typedef unsigned int Uint; // typedef start with capital letter as like class
#define PI 3.14;
int g_var = 2;       // convention for global variable
const int c_var = 3; // convention for global const variable
int main()
{
    int a{9};  // uniform initialisation
    int b(0);  // constructor like initialisation
    int c = 1; // c like initialisation
    int val = 2;
    int vaL = 4; // val and vaL will be treated as different identifiers/variables
    float result = val * val * PI;
    cout << "Area of circle is " << setw(15) << result << endl; // setw() used to append space as prefix (present in iomanip header) && setfill() fills the spaces with some character
    cout << "Area of circle is " << setw(15) << setfill('-') << result << endl;

    int n = 8;
    cout << dec << n << endl;
    cout << hex << n << endl; // 9+1=a
    cout << oct << n << endl; // 8+1=a

    double d = 4.2455366399;
    cout << d << endl; // by default precision while cout is 5 so its rounding off d upto 5 decimal points
    cout.precision(8); // changed the precision to print upto 8 decimal places . So the value is rounding off and making 7 digits decimal expansion
    cout << d << endl;
    // cout << fixed << d << endl; // fixed stop rounding off the no. and prints the decimal expansion upto 8 without rounding off
    double e = 30;
    double f = 10000.032;
    double pi = 3.1416;
    std::cout.precision(5);
    std::cout << std::showpoint << e << '\t' << f << '\t' << pi << '\n';
    std::cout << std::noshowpoint << e << '\t' << f << '\t' << pi << '\n';

    double g = 3.14159;
    std::cout << std::setprecision(5) << g << '\n';
    std::cout << std::setprecision(9) << g << '\n';
    std::cout << std::fixed;
    std::cout << std::setprecision(5) << g << '\n';
    std::cout << std::setprecision(9) << g << '\n';

    // endl create buffer and '\n' doesnot

    return 0;
}