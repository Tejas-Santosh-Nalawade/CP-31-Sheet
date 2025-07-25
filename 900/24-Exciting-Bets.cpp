#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        cin >> a >> b;
        if (b > a)
            swap(a, b); 

        if (a == b)
            cout << 0 << " " << 0 << "\n"; 
        else
        {
            long long gcd = a - b;
            long long moves = min(b % gcd, gcd - b % gcd);
            cout << gcd << " " << moves << "\n";
        }
    }
    return 0;
}
