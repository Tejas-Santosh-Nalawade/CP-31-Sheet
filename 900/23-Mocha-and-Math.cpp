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
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        long long total_and = a[0];
        for (long long i = 1; i < n; i++) 
            total_and &= a[i];

        cout << total_and << "\n";
    }
    return 0;
}

 