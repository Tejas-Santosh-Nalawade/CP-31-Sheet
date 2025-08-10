#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        long long ans_a = 1;
        long long ans_b = n - 1;
        for (long long fac = 2; fac * fac <= n; fac++)
        {
            if (n % fac == 0)
            {
                ans_a = n / fac;
                ans_b = n - ans_a;
                break;
            }
        }
        cout << ans_a << " " << ans_b << "\n";
    }
    return 0;
}