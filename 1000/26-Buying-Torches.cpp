#include <bits/stdc++.h>
using namespace std;

long long ceil_division(long long a, long long b) { return (a + b - 1) / b; }

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long x, y, k;
        cin >> x >> y >> k;
        long long sticks_gained_per_trade = x - 1; 
        long long sticks_needed = k * y + k - 1;

        long long trades = 0;
        trades += ceil_division(sticks_needed, sticks_gained_per_trade); 
        trades += k;
        cout << trades << "\n";
    }
}
