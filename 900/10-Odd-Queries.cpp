#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n, q;
        cin >> n >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        long long old_sum = 0;
        for (int i = 0; i < n; i++) 
            old_sum += a[i];

        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) 
            prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];

        while (q--)
        {
            long long l, r, k;
            cin >> l >> r >> k;
            long long sum_to_remove = prefix_sum[r] - prefix_sum[l - 1];
            long long sum_to_add = (r - l + 1) * k;
            long long total_sum = old_sum - sum_to_remove + sum_to_add;
            if (total_sum % 2 == 1)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    return 0;
}