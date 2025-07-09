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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        
        int k = abs(a[0] - 1);
        for (int i = 1; i < n; i++) 
        {
            k = gcd(k, abs(a[i] - (i + 1)));
        }
        cout << k << "\n";
    }
    return 0;
}