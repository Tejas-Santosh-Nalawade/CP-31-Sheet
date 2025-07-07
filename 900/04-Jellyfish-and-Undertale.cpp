#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b, n;
        cin >> a >> b >> n;
        long long x[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        long long maximum_time = b;
        for (int i = 0; i < n; i++) 
            maximum_time += min(x[i], a - 1);

        cout << maximum_time << "\n";
    }
    return 0;
}