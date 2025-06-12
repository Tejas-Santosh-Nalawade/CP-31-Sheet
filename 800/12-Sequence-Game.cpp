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
        vector<long long> b(n), a;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        a.push_back(b[0]);
        for (int i = 1; i < n; i++)
        {
            if (b[i] >= b[i - 1])
            {
                a.push_back(b[i]);
            }
            else
            {
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
        }
        cout << a.size() << "\n";
        for (auto it : a)
        {
            cout << it << " ";
        }
        cout<<"\n";
    }
        return 0;
}