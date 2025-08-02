#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, p;
        cin >> n >> p;
        vector<pair<long long, long long> > v(n);
        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
            v[i] = {b[i], a[i]};

        sort(v.begin(), v.end());

        long long minimum_cost = p;
        long long already_shared = 1;

        for (auto it : v)
        {
            long long can_be_shared = it.second;
            long long sharing_cost = it.first;

            if (sharing_cost >= p)
                break;

            if (already_shared + can_be_shared > n)
            {
                minimum_cost += (n - already_shared) * sharing_cost;
                already_shared = n;
                break;
            }
            else
            {
                minimum_cost += can_be_shared * sharing_cost;
                already_shared += can_be_shared;
            }
        }

        minimum_cost += (n - already_shared) * p; 
        cout << minimum_cost << "\n";
    }
    return 0;
}

