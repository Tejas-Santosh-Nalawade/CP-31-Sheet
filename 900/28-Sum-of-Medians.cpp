#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt
    cin >> tt;
    while (tt--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n * k);
        for (int i = 0; i < n * k; i++) 
            cin >> v[i];

        long long pointer = n * k;

        long long sum = 0;
        while (k--) // k
        {
            pointer -= (n / 2 + 1);
            sum += v[pointer];
        }
        cout << sum << "\n";
    }
    return 0;
}