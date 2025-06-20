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
        long long a[n];
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
 
        for (int i = 0; i < n; i++) // n
        {
            cout << n + 1 - a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}