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
        string s; 
        cin >> s; 
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) 
            prefix[i + 1] = prefix[i] + (s[i] == 'W');

        long long minimum_cells = INT_MAX;
        for (int i = 0; i <= n - k; i++) 
        {
            long long diff = prefix[i + k] - prefix[i];
            minimum_cells = min(minimum_cells, diff);
        }

        cout << minimum_cells << "\n";
    }
    return 0;
}