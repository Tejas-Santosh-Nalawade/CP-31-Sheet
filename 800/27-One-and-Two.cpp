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
        long long total_number_of_twos = 0;
        long long current_number_of_twos = 0;
 
        for (long long i = 0; i < n; i++) 
        {
            if (a[i] == 2)
                total_number_of_twos++;
        }
 
        long long ans = -1;

        for (long long i = 0; i < n; i++) 
        {
            if (a[i] == 2)
                current_number_of_twos++;
 
            if ((current_number_of_twos) == (total_number_of_twos - current_number_of_twos))
            {
                ans = i + 1;
                break;
            }
        }
 
        cout << ans << endl;
    }
    return 0;
    }
        