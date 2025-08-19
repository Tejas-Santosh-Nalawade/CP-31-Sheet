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

        vector<pair<long long, long long> > building_map;
        for (int i = 0; i < n; i++) 
            building_map.push_back({a[i], i});

        sort(building_map.rbegin(), building_map.rend()); 

        vector<long long> ans(n + 1, 0);

        ans[0] = 0;

        long long minutes = 0;
        long long coordinate = 1;
        for (int i = 0; i < n; i++)
        {
            ans[building_map[i].second + 1] = coordinate;
            minutes += (2 * abs(coordinate) * building_map[i].first);
            if (coordinate < 0)
                coordinate = abs(coordinate) + 1;
            else
                coordinate = -coordinate;
        }
        
        cout << minutes << "\n";
        for (auto it : ans)
            cout << it << " ";
        cout << "\n";  
     }
}