#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt; 
    while (tt--)
    {
        long long n, a, b;
        cin >> n >> a >> b; 
        if (a + b + 2 <= n || (a == b && a == n)) 
            cout << "Yes" << "\n"; 
        else
            cout << "No" << "\n"; 
    }
    return 0;
}