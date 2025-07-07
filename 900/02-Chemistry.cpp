#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tt;
    cin >> tt;
    while (tt--)
    {
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> frequency_of_characters(26, 0);
        for (int i = 0; i < n; i++) 
            frequency_of_characters[s[i] - 'a']++;

        long long odd_frequency = 0;
        for (int i = 0; i < 26; i++) 
            odd_frequency += frequency_of_characters[i] % 2;

        if (odd_frequency > k + 1)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
    return 0;
}