#include <iostream>
using namespace std;
bool checkPrime(int n)
{
   if (n <= 1)
   {
      return 0;
   }
   for (int i = 2; i * i <= n; i++)
   {
      if (n % i == 0)
      {
         return 0;
      }
   }
   return 1;
}
int main()
{
   int n;
   cin >> n;
   int primes[n] = {0};
   int k = 0;

   for (int i = 2; i <= n; i++)
   {
      if (checkPrime(i))
      {
         primes[k] = i;
         k++;
      }
   }
   int a = -1, b = -1;
   for (int i = 0; i < n - 1; i++)
   {
      if (primes[i + 1] - primes[i] == 2)
      {
         a = primes[i];
         b = primes[i + 1];
      }
   }
   cout << a << " " << b << endl;

   return 0;
}