#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int func(vector<int>& a) {
    sort(begin(a), end(a));
    int x = a[0];
    for (auto& val: a)
        val -= x;
    int g = 0;
    for (auto& val: a)
        g = gcd(g, val);
    return g;
}

void solve() {
    int n;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 1;
    for (int k = 1; k < n; k++) {
        if (n % k != 0)
            continue;
        int gg = 0;
        for (int z = 0; z < k; z++) {
            vector<int> v;
            for (int i = z; i < n; i += k)
                v.push_back(a[i]);
            int g = func(v);
            gg = gcd(gg, g);
        }
        if (gg != 1)
            ans++;
    }

    cout << ans << endl;
}

int main() {
    int t;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
        solve();

    return 0;
}
