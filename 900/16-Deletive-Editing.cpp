#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long tt;
    cin >> tt;
    while (tt--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();

        vector<int> frequency_in_t(26, 0);
        for (int i = 0; i < m; i++) 
            frequency_in_t[t[i] - 'A']++;

        for (int i = n - 1; i >= 0; i--) 
        {
            if (frequency_in_t[s[i] - 'A'] > 0)
                frequency_in_t[s[i] - 'A']--;
            else
                s[i] = '.';
        }

        string final_string = "";

        for (int i = 0; i < n; i++) 
        {
            if (s[i] != '.')
                final_string += s[i];
        }

        if (final_string == t) 
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}