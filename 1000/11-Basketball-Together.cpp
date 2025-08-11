#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, d;
    cin >> n >> d;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end()); 
    long long left = -1;
    long long right = n - 1;
    long long team_size = 1;
    long long teams = 0;

    while (left < right)
    {
        if ((a[right] * team_size) <= d && left < right)
        {
            left++;
            team_size++;
        }
        else
        {
            teams++;
            right--;
            team_size = 1;
        }
    }

    cout << teams << "\n";
    return 0;
}