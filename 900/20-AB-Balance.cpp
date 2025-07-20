#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        string s;
        cin >> s;
        int n = s.size();

        if (s[0] != s[n - 1])
        {
            if (s[0] == 'a')
                s[0] = 'b';
            else
                s[0] = 'a';
        }

        cout << s << "\n";
    }
    return 0;
}

