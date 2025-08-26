#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) 
            cin >> a[i];
        
        unordered_set<long long> s;
        for (long long i = 0; i < n; i++) 
            s.insert(a[i]); 

        if (s.size() < n)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}