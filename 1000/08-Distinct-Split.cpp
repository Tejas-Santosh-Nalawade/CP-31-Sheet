#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;

        unordered_set<char> st;
        vector<long long> prefix_unique_count(n + 1, 0);
        vector<long long> suffix_unique_count(n + 1, 0);

        for (long long i = 1; i <= n; i++) 
        {
            st.insert(s[i - 1]); 
            prefix_unique_count[i] = st.size(); 
        }

        st.clear();

        for (long long i = n; i >= 1; i--) 
        {
            st.insert(s[i - 1]);
            suffix_unique_count[i] = st.size();
        }

        long long ans = 0;
        for (long long i = 0; i < n; i++)
            ans = max(ans, prefix_unique_count[i] + suffix_unique_count[i + 1]);
        cout << ans << endl;
    }
    return 0;
}

