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
        long long a[n];
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];

        long long operations_count = 0;

        for (long long i = 0; i < n - 1; i++)
        {
            if ((a[i] % 2) == (a[i + 1] % 2))
                operations_count++;
        }
        cout << operations_count << "\n";
    }
    return 0;
}