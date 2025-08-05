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
        vector<pair<long long, long long> > health_points(n);
        for (long long i = 0; i < n; i++) 
        {
            long long x;
            cin >> x;
            health_points[i] = { x, i + 1 };
        }

        for (long long i = 0; i < n; i++) 
        {
            health_points[i].first = health_points[i].first % k;
            if (health_points[i].first == 0)
                health_points[i].first = k;
        }

        sort(health_points.begin(), health_points.end(), [&](pair<long long, long long> a, pair<long long, long long> b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }); 

        for (auto it : health_points) 
            cout << it.second << " ";
        cout << "\n";
    }
    return 0;
}