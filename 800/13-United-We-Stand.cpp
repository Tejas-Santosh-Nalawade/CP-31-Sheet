#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<long long> b, c;
        long long mx = *max_element(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (a[i] != mx)
            {
                b.push_back(a[i]);
            }
            else
            {
                c.push_back(a[i]);
            }
        }
        if (b.size() == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << b.size() << " " << c.size() << "\n";
            for (auto it : b)
            {
                cout << it<<" ";
                
            }
            cout<<"\n";
            for(auto it: c)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}