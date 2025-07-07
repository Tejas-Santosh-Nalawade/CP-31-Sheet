#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        sort(a.begin(), a.end()); 

        long long counter = 1;
        long long largest_length = 1;
        for (int i = 1; i < n; i++) 
        {
            if (a[i] - a[i - 1] <= k)
                counter++;
            else
                counter = 1;
            largest_length = max(largest_length, counter);
        }

        cout << n - largest_length <<"\n";
    }
    return 0;
}