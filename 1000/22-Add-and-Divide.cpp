#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        cin >> a >> b;

        long long ans = INT_MAX;
        for (int addition = 0; addition < 32; addition++)
        {
            long long operations = addition;
            long long new_b = b + addition;
            if (new_b == 1) 
                continue;
            long long copy_a = a;
            while (copy_a > 0) 
            {
                copy_a /= new_b;
                operations++;
            }
            ans = min(ans, operations);
        }
        cout << ans << "\n";
    }
}
