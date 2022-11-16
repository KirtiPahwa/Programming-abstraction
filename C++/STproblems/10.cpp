#include <iostream>
using namespace std;
void countSquares(int b)
{
    int cnt = 0; // Initialize result

    // Traverse through all numbers
    for (int i = 1; i <= b; i++)

        // Check if current number 'i' is perfect
        // square
        for (int j = 1; j * j <= i; j++)
            if (j * j == i)
                cout << i << " ";
}
int main()
{
    int n;
    cin >> n;
    countSquares(n);

    // find the number who have perfect squares

    // A door is toggled in an ith walk if i divide door number. For example, door number 45 is toggled in the 1st, 3rd, 5th, 9th,15th, and 45th walks.
    // The door is switched back to an initial stage for every pair of divisors. For example, 45 is toggled 6 times for 3 pairs (5, 9), (15, 3), and (1, 45).

    // It looks like all doors would become closed at the end. But there are door numbers that would open, for example, in 16, the divisors are (1,2,4,8,16) and as the pair(4,4) contributes only one divisor making the number of divisors odd, it would become open at the end. Similarly, all other perfect squares like 4, 9,…, and 100 would become open. Now, for prime numbers like 2,3,5,7… the divisors are (1, that number) and it is a pair, so they will remain closed at the end. And for all other numbers divisors are always in pairs, e.g. 15 = (1,15),(3,5), they will also remain closed.

    // So the answer is 1, 4, 9, 16, 25, 36, 49, 64, 81 and 100.

    return 0;
}