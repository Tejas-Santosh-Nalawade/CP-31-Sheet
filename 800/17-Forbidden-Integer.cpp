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
        long long n, k, x;
        cin >> n >> k >> x;
        
        if (x != 1)
        {
            cout << "YES" << "\n";
            cout << n << "\n";
            for (int i = 1; i <= n; i++) 
                cout << 1 << " ";
            cout << "\n";
        }
        else
        {
            if (k == 1 || (k == 2 && n % 2 == 1))
                cout << "NO" << "\n";
            else
            {
                cout << "YES" << "\n";
                if (n % 2 == 0)
                {
                    cout << n / 2 << "\n";
                    for (int i = 1; i <= n / 2; i++) 
                        cout << 2 << " ";
                    cout << "\n";
                }
                else
                {
                    cout << (n - 3) / 2 + 1 << "\n";
                    for (int i = 1; i <= (n - 3) / 2; i++) 
                        cout << 2 << " ";
                    cout << 3 << "\n";
                }
            }
        }
    }
    return 0;
}