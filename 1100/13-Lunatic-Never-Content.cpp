#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = __gcd(ans, abs(a[i] - a[n - i - 1]));
    }
    cout << ans << "\n";
}
 
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}