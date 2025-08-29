#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        cin >> a >> b;
        long long ra = a;
        long long rb = b;
        while (ra % 2 == 0) 
            ra /= 2;
        while (rb % 2 == 0) 
            rb /= 2;

        if (ra != rb)
            cout << -1 << "\n";
        else
        {
            a /= ra;
            b /= rb;
            a = log2(a); 
            b = log2(b); 
            long long ans = ceil(abs(a - b) / 3.0);
            cout << ans << "\n";
        }
    }
    return 0;
}
