#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, x;
        cin >> n >> x;

        if (n == x)
        {

            cout << n << '\n';
            continue;
        }

        ll ans = -1;
        for (int i = 0; i <= 61; i++)
        {
            if (((n >> i) << i) == x)
            {

                ll m = x | (1LL << i);
                ans = (m >= n) ? m : -1;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
