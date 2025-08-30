#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) 
            cin >> a[i];

        sort(a.rbegin(), a.rend()); 

        for (auto ele : a)
            cout << ele << " ";
        cout << "\n";
    }
    return 0;
}
