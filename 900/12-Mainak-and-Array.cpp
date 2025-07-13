#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++) 
            cin >> v[i];

        long long answer = v[n - 1] - v[0];

        for (int i = 1; i < n; i++) 
            answer = max(answer, v[i] - v[0]);
        for (int i = 0; i < n - 1; i++)
            answer = max(answer, v[n - 1] - v[i]);
        for (int i = 0; i < n - 1; i++)
            answer = max(answer, v[i] - v[i + 1]);

        cout << answer << endl;
    }
    return 0;
}